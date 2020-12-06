function wyswietlAlert() {
 window.alert('Komunikat!');
}

function nalicz_3() {
 var stan = 0;
 switch(document.forms.formularz.stan.value) {
 case "1": stan = 0.8; break;
 case "2": stan = 0.9; break;
 case "3": stan = 1.0; break;
 case "4": stan = 1.1; break;
 case "5": stan = 1.2; break;
 }

 document.formularz.cena_stan.value = document.formularz.cena_pln.value * stan;
}

function nalicz_33() {
 var stan = 0;
 switch(document.forms.formularz.stan.value) {
 case "1": stan = 0.8; break;
 case "2": stan = 0.9; break;
 case "3": stan = 1.0; break;
 case "4": stan = 1.1; break;
 case "5": stan = 1.2; break;
 }

 document.formularz.cena_stan.value = document.formularz.cena_pln.value * stan;
}

function wypisz() {
    {
        alert(' zostałem kliknięty! ');
    }

document.getElementById('guzik').onclick = wypisz();}
