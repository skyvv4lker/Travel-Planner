from flask import Flask, render_template, request, redirect, url_for
import subprocess
import os

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        origin = request.form["origin"]
        destination = request.form["destination"]
        preference = request.form["preference"]

        # Path to C++ binary
        binary_path = os.path.join("..", "cpp", "travel")

        # Input + output files
        cities_file = os.path.join("..", "data", "cities.csv")
        edges_file = os.path.join("..", "data", "edges.csv")
        output_file = os.path.join("web", "static", "output.html")

        # Run the C++ program
        subprocess.run([binary_path, cities_file, edges_file, output_file, origin, destination, preference])

        return redirect(url_for("result"))

    return render_template("index.html")

@app.route("/result")
def result():
    return render_template("result.html")

if __name__ == "__main__":
    app.run(debug=True)
