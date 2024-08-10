# Azure Provider source and version being used
terraform {
  required_providers {
    azurerm = {
      source  = "hashicorp/azurerm"
      version = "= 3.0.0"
    }
  }
}

# Configure the Microsoft Azure Provider
provider "azurerm" {
  features {}
}

#Resource Group
resource "azurerm_resource_group" "am_rg" {
  name     = "AM_rg"
  location = "Norway East"

  tags = {
    environment = "dev"
  }
}

#Virtual Nettverk
resource "azurerm_virtual_network" "am_vn" {
  name                = "AM-Nettvek"
  resource_group_name = azurerm_resource_group.am_rg.name
  location            = azurerm_resource_group.am_rg.location
  address_space       = ["10.10.0.0/16"]

  tags = {
    environment = "dev"
  }

}

#Subnet innad i Virtuel nettverket
resource "azurerm_subnet" "am_subnet" {
  name                 = "am_subnet"
  resource_group_name  = azurerm_resource_group.am_rg.name
  virtual_network_name = azurerm_virtual_network.am_vn.name
  address_prefixes     = ["10.10.1.0/24"]
}

resource "azurerm_network_security_group" "am_sec_group" {
  name                = "AM_Sec_Group"
  location            = azurerm_resource_group.am_rg.location
  resource_group_name = azurerm_resource_group.am_rg.name

  tags = {
    environment = "dev"
  }
}

#Regel for å akseptere trafikk inkommende fra min IP adresse.
resource "azurerm_network_security_rule" "am_sec_IP_rule" {
  name                       = "Source_IP_Rule"
  priority                   = 100
  direction                  = "Inbound" #hvem som skal få lov til å sende trafikk inn i nettverket (bare din IP)
  access                     = "Allow"
  protocol                   = "*"
  source_port_range          = "*"
  destination_port_range     = "*"
  source_address_prefix      = "var.my_ip_address" #Verdi Hentes fra variabel fil
  destination_address_prefix = "*"

  resource_group_name         = azurerm_resource_group.am_rg.name
  network_security_group_name = azurerm_network_security_group.am_sec_group.name

}
#Regel for å blokkere all annen trafikk inbound
resource "azurerm_network_security_rule" "am_sec_Deny_rule" {

  name                       = "DenyAllOthers"
  priority                   = 200
  direction                  = "Inbound"
  access                     = "Deny"
  protocol                   = "*"
  source_port_range          = "*"
  destination_port_range     = "*"
  source_address_prefix      = my_ip_address
  destination_address_prefix = "*"

  resource_group_name         = azurerm_resource_group.am_rg.name
  network_security_group_name = azurerm_network_security_group.am_sec_group.name

}

#Assosierer Security Gruppa som nå har 2 regler, opp mot subnettet vårt 
resource "azurerm_subnet_network_security_group_association" "am_sec_subnet" {
  network_security_group_id = azurerm_network_security_group.am_sec_group.id
  subnet_id                 = azurerm_subnet.am_subnet.id
}

resource "azurerm_public_ip" "am_vm_public_ip" {
  name                = "Linux_VM_IP"
  resource_group_name = azurerm_resource_group.am_rg.name
  location            = azurerm_resource_group.am_rg.location
  allocation_method   = "Dynamic"

  tags = {
    environment = "dev"
  }
}

resource "azurerm_network_interface" "am_nic_linux" {
  name                = "am-linux-nic"
  location            = azurerm_resource_group.am_rg.location
  resource_group_name = azurerm_resource_group.am_rg.name

  ip_configuration {
    name                          = "internal"
    subnet_id                     = azurerm_subnet.am_subnet.id
    private_ip_address_allocation = "Dynamic"
    public_ip_address_id          = azurerm_public_ip.am_vm_public_ip.id
  }
  tags = {
    environment = "dev"
  }
}

resource "azurerm_linux_virtual_machine" "am_vm_docker" {
  name                  = "Linux-Docker-Machine-1"
  resource_group_name   = azurerm_resource_group.am_rg.name
  location              = azurerm_resource_group.am_rg.location
  size                  = "Standard_B1s"
  admin_username        = "adminUser"
  network_interface_ids = [azurerm_network_interface.am_nic_linux.id]

  custom_data = filebase64("customdata.tpl") #Docker install for Linux VM

  admin_ssh_key {
    username   = "adminUser"
    public_key = file("~/.ssh/azure_key.pub")
  }

  os_disk {
    caching              = "ReadWrite"
    storage_account_type = "Standard_LRS"
  }

  source_image_reference {
    publisher = "Canonical"
    offer     = "UbuntuServer"
    sku       = "18.04-LTS"
    version   = "latest"
  }

  tags = {
    environment = "dev"
  }
}