#!/usr/bin/python

import sys
import json
import random
import subprocess

trigger = False
last_rockstar = None

class Rockstar:

    def __init__(self, name, age, notes, rockstar_type, rockstar_file):
        self.name = name
        self.age = age
        self.notes = notes
        self.rockstar_type = rockstar_type
        self.rockstar_file = rockstar_file
        self.rockstar_desc = file("./profiles/" + self.rockstar_file).read()
        self.savedata = {"profile": {"name": self.name,
                                     "age": self.age,
                                     "notes": self.notes,
                                     "rockstar": self.rockstar_type,
                                     "rockstar_file": self.rockstar_file,
                                     }
                         }



    def fields(self):
        savedata_output = json.dumps(self.savedata).encode("base64")
        return (self.name, self.age, self.notes, self.rockstar_type,
                self.rockstar_desc, savedata_output)

def write(data, ending="\n"):
    sys.stdout.write(data + ending)
    sys.stdout.flush()

def readline():
    return sys.stdin.readline()

def print_menu():
    write("Welcome to the Rockstar Creation Service.")
    write("1. Create a rockstar")
    write("2. Random a rockstar")
    write("3. Load a rockstar")
    write("4. Quit")

def handle_input():
    write("> ", "")
    response = readline().strip()
    if response.isdigit():
        handlers[int(response)]()
    else:
        write("404")

def generate():
    name = "Placeholder name"
    age = 21
    notes = "Placeholder notes"
    rockstar_type = random.choice(["classicrocker", "goth", "hairrocker",
                              "punkrocker", "speedrocker"])
    rockstar_file = rockstar_type + ".rk"

    rockstar = Rockstar(name, age, notes, rockstar_type, rockstar_file)

    output = """
    Name: %s
    Age: %d
    Notes: "%s"
    Rockstar Type: %s
    Rockstar Description: %s

    Save Data: %s""" % rockstar.fields()
    write(output)
    global last_rockstar
    last_rockstar = rockstar

def create():
    write("Sorry, but we disabled this feature due to abuse.")

def cleanup():
    rockstar = last_rockstar
    params = ["./bin/tastyriffs"]
    params.extend(rockstar.fields())
    result = subprocess.call([str(i) for i in params])
    if result == 0:
        return "Application works properly."
    else:
        return "Something happened."

def randomise():
    rockstar = generate()
    write("Congratulations on your new rockstar!")
    write("This is your rockstar profile. Keep it safe!")

def loading():
    write("Please enter your rockstar profile: ", "")
    rockstar_response = readline().strip()
    rockstar_data_raw = json.loads(rockstar_response.decode('base64'))
    rockstar_data = rockstar_data_raw['profile']
    rockstar = Rockstar(rockstar_data['name'], rockstar_data['age'],
                        rockstar_data['notes'], rockstar_data['rockstar'],
                        rockstar_data['rockstar_file'])
    write("Successfully loaded your rockstar!")
    output = """
    Name: %s
    Age: %d
    Notes: "%s"
    Rockstar Type: %s
    Rockstar Description: %s
    """ % rockstar.fields()[:-1]
    write(output)
    global last_rockstar
    last_rockstar = rockstar

def secretive():
    global trigger
    trigger = True

def goodbye():
    write("Cleaning it all up...")
    if trigger:
        write(cleanup())
        write("Did you get your shell yet?")
    write("Goodbye")
    sys.exit()

handlers = {1: create, 2: randomise, 3: loading, 4: goodbye,
            int(file("picpic").read()): secretive}

def main():
    while True:
        print_menu()
        handle_input()

if __name__ == "__main__":
    main()
