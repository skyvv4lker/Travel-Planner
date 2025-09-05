from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route("/find-route", methods=["POST"])
def find_route():
    data = request.get_json()
    source = data.get("source")
    destination = data.get("destination")
    preference = data.get("preference")

    try:
        # Call compiled C++ program
        result = subprocess.check_output(
            ["../cpp/dijkstra", source, destination, preference],
            universal_newlines=True
        )
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    return jsonify({"output": result})

if __name__ == "__main__":
    app.run(debug=True)
