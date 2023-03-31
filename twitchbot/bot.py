           # os hjelper oss med å knytte variabler under bot nedenfor med environment variablene vi lagde i .env
import os  #lets us get the api information from the env file we made 
from twitchio.ext import commands

bot = commands.Bot(

irc_token=os.environ['TMI_TOKEN'],
client_id=os.environ['CLIENT_ID'],
nick=os.environ['BOT_NAME'],
prefix=os.environ['BOT_PREFIX'],
initial_channels=[os.environ['CHANNEL']]
)

if __ name __ == "__ main __":
bot.run()