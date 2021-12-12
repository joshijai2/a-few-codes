let file = document.getElementById("file");
let data = new FormData();
data.append("Name", "Jai Joshi");
data.append("Email", "joshi.jai232@gmail.com");
data.append("College", "Vellore Institute of Technology");
data.append("StudentId", "18BIT0239");
data.append("FileName", file.files[0],"bajajPutReq.js");
data.append("Password", "jJ52452320");

let xhr = new XMLHttpRequest();

xhr.addEventListener("readystatechange", function() {
  if(this.readyState === 4) {
    console.log(this.responseText);
  }
});

const endpoint = "https://prod-24.centralindia.logic.azure.com/workflows/78d6df0ed1384ee0b7d04918f1a32b85/triggers/request/paths/invoke?api-version=2016-10-01&sp=%2Ftriggers%2Frequest%2Frun&sv=1.0&sig=i6gXuS7-5_fFVf-0u8M4UfymINDULCMifsscfN5cPKM"

xhr.open("PUT", endpoint);
xhr.setRequestHeader("Content-Type", "application/json");

xhr.send(data); 