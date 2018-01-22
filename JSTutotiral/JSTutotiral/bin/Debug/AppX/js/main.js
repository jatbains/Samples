// Your code here!

var yourName = prompt("What is your name?");

if (yourName != null) {
    document.getElementById("Hello").innerHTML = "Hello " + yourName;
}
else {
    prompt("Please enter a name");
}
