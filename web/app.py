from flask import Flask, render_template, request, redirect, url_for
import subprocess
import os

app = Flask(__name__)

# Paths relative to this file
CPP_DIR = os.path.join("..", "cpp")
DOCS_DIR = os.path.join("..", "docs")
STATIC_DIR = "static"

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        origin = request.form["origin"]
        destination = request.form["destination"]
        preference = request.form["preference"]

        # Paths
        binary_path = os.path.join(CPP_DIR, "travel")
        cities_file = os.path.join(DOCS_DIR, "cities.csv")
        edges_file = os.path.join(DOCS_DIR, "routes.csv")
        output_file = os.path.join(STATIC_DIR, "output.html")

        # Run C++ binary
        subprocess.run([binary_path, cities_file, edges_file, output_file, origin, destination, preference])

        return redirect(url_for("result"))

    return render_template("index.html")


@app.route("/result")
def result():
    return render_template("result.html")


if __name__ == "__main__":
    # HTTPS for local development
    app.run(debug=True, ssl_context='adhoc')
