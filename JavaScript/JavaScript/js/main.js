// Your code here!
var temp = 100;
var i= 0;
for ( i= 0; i < 100; i++)
{
   // document.write(i +" " + "<br/>");
}

function fact(num) {
    if (num == 0)
        return 1;
    return (num * fact(num - 1));
}

document.write(getSum(10, 5), "<br/>");

document.writeln("Fact is =", fact(5) ,"<br/>");

function getSum(x, y) {
    return x + y;
}