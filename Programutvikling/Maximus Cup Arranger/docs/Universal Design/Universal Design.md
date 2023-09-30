# Universal design 

Acronym - CLI (Command line interface)

## [WCAG 2.1](https://www.w3.org/TR/WCAG21/#intro)
The application is expected to be designed according to the [WCAG 2.1](https://www.w3.org/TR/2018/REC-WCAG21-20180605/#requirements-for-wcag-2-1) principle 1 to achive high level of usability for any user, including those with disabilities.

## Principle 1: [Perceivable](https://www.w3.org/TR/WCAG21/#perceivable)
This section of the guidelines is primarly focused making sure informastion is presented to the user in a way they can percive.

### 1.1 Text alternatives
The main goal is to have alternatives to non-text content by giving options such as braille, speech or symbols or simpler language. Since our application is only accessible through a command line interface this point is non-applicable.

### 1.2 Time-based Media
Providing alternatives for time-based media such as audio clips or videos by giving alternatives like cations or sign language. This point is non-applicable since our program only involves text.

### 1.3 Adaptable
Main goal is to create content that can be offered in multiple ways without losing structure or information.

### 1.4 Distinguishable 

Make it easier for users to see and hear content including separating foreground from background.


----------------------------------------------------------------------------------------------------------------------------------------------------
**Success Criterion 1.3.4** [Orientation](https://www.w3.org/TR/WCAG21/#orientation)
There are limited options available for customization on a CLI, but one way we can impact the user experience is text wrapping. By making sure the text doesn’t go out of the window size we avoid confusion and make it easier for the user to understand what is being presented on the screen. 

**Success Criterion 1.4.1** [Use of Color](https://www.w3.org/TR/WCAG21/#use-of-color)
The command line interface will only display text in the terminal. The colour of the background and text is not something we can control, but is based on the colour scheme of the users terminal. This is usually a plain black or blue background and plain white or green text colour.

**Success Criterion 1.4.4** [Resize text](https://www.w3.org/TR/WCAG21/#resize-text)
The command line interface allows users to resize their text without the loss of content or functionality. Either by manually changing the setting of zoom, or by using shortcuts like Ctrl and +/-  on Windows or Command  and +/- on Mac OS.

**Success Criterion 1.4.10** [Reflow](https://www.w3.org/TR/WCAG21/#reflow)
The program does not require users to scroll when presenting information. New information displayed will always emerge bottom up on the CLI. Whenever new text appears the CLI will always scroll down to the button where the new information is displayed.

----------------------------------------------------------------------------------------------------------------------------------------------------

# Don Norman's Principles of interaction design
It is also expected that the application relates to Donald Norman's principles of interaction design to ensure high usability and good user experience.

**Visibility:** Our program is made to be used only in text format in a command line interface. Since we are making the program, the information displayed for the user will all be relevant. Available options are described on screen in a simple understandable way. Information regarding how to navigate the program is written in more detail in the user manual. 

**Feedback:** After every action taken by the user the program will give feedback indicating if the entered data is accepted/declined or if something went wrong. Options users have to go forward will also be presented after each action is taken. Since the program is only available in a command line interface, the history is always easily accessible for the user by scrolling up.

**Constraints:** Since we are making the program ourselves, we have full control over which actions the user can take at any given place in the program. The program will constrain the user by only allowing input that we have predetermined as acceptable.

**Mapping:** A command is linked to each option in the different menus. The user will be shown which options are available at any given moment and easy keyboard presses performs each option.

**Consistency:** For the sake of simplicity and improving the user experience similar actions have the same input through the program.

**Affordance:** Since our program is only available in a command line interface, the prior knowledge a user has with a CLI will determine how easily they pick up on the program. The user manual will help users understand how to use the program, but the program will also display all options available at any given moment.





