var hid = 0;
function check(a, b){
    if(a == "" || b == ""){
        window.alert("Proszę wypełnić WSZYTSKIE okna!");
        return false;
    }
    else if(isNaN(a) || isNaN(b)){
        window.alert("Proszę wypełnić okna LICZBAMI!");
        return false;
    }
    else{
        return true;
    }
}

function action(){
    let history = '';
    var pop = check(document.getElementById("elem1").value, document.getElementById("elem2").value);
    if(pop == true){
    const a = parseInt(document.getElementById("elem1").value);
    const b = parseInt(document.getElementById("elem2").value);
    document.getElementById("result").readOnly = true;

    switch(document.getElementById('action').value){
        case "+":
            var add = a+b;
            document.getElementById("result").value = add;
            history += a + " + " + b + " = " + add;
            ++hid;
            document.getElementById("history").innerHTML += "<p id = 'history-" + hid + "'>" + history + "</p>";
        break;
        case "-":
            var sub = a-b;
            document.getElementById("result").value = sub;
            history += a + " - " + b + " = " + sub;
            ++hid;
            document.getElementById("history").innerHTML += "<p id = 'history-" + hid + "'>" + history + "</p>";
        break;
        case "*":
            var mul = a*b;
            document.getElementById("result").value = mul;
            history += a + " * " + b + " = " + mul;
            ++hid;
            document.getElementById("history").innerHTML += "<p id = 'history-" + hid + "'>" + history + "</p>";
        break;
        case "/":
            var div = a/b;
            document.getElementById("result").value = div;
            history += a + " / " + b + " = " + div;
            ++hid;
            document.getElementById("history").innerHTML += "<p id = 'history-" + hid + "'>" + history + "</p>";
        break;
        case "%":
            var mod = a%b;
            document.getElementById("result").value = mod;
            history += a + " % " + b + " = " + mod;
            ++hid;
            document.getElementById("history").innerHTML += "<p id = 'history-" + hid + "'>" + history + "</p>";
        break;
    }
}
}
