document.addEventListener("DOMContentLoaded", start());
const fs = require('fs');


function removeDisplay(elem){
	elem.style.display = "none";
}

const options = {"clownfish":"4.4", "salmon":"3.4", "koi":"3.6", "shark":"11.7",
				 "anchovy":"3", "pufferfish":"2", "guppy":"1.8", "name": ""};



function pickFish(name){
	var fish1 = document.getElementById(name);
	var allfish = Array.from(document.getElementsByClassName("fish"));

	if (fish1.style.display === "none") {
		allfish.forEach(removeDisplay);
    	fish1.style.display = "flex";
  	} else {
    	fish1.style.display = "none";
  	}
  	options["name"] = name;
  	sendJSON();

}


function start(){
	alert("Pick a fish to get started!")
}

function sendJSON(){
	let xhr = new XMLHttpRequest();
	let url = "fish.php";

	xhr.open("GET", url, true);
	
	xhr.onload = function(){
		
	}

	var fishPicked = JSON.stringify(options);

	xhr.send(fishPicked);
}





