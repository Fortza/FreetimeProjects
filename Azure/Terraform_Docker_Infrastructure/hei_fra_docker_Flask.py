from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
    return "Hei! \n Velkommen til en nettside som kjører på Docker, på en Azure VM."

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000)
