document.getElementById("plannerForm").addEventListener("submit", async function(e) {
  e.preventDefault();

  const source = document.getElementById("source").value;
  const destination = document.getElementById("destination").value;
  const preference = document.getElementById("preference").value;

  try {
    const response = await fetch("http://127.0.0.1:5000/find-route", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ source, destination, preference })
    });

    const data = await response.json();

    if (data.error) {
      document.getElementById("result").innerText = "Error: " + data.error;
    } else {
      document.getElementById("result").innerText = data.output;
    }
  } catch (err) {
    document.getElementById("result").innerText = "Request failed: " + err;
  }
});
