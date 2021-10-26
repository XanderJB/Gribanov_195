var rouble = prompt("Введите сумму в рублях: "); //сумма в рублях которую вводит пользователь
var dollar = 70.96; //сегодняшний курс доллара
var euro = 82.68; //сегодняшний курс евро

rouble = parseInt(rouble); //передаем численные значения в рубль

var Itog = rouble / dollar; //вычисление количества рублей в долларах
var Itog_1 = rouble / euro; 
alert("Итого: " + Itog.toFixed(2) + " долларов" +  "\nИтого: " + Itog_1.toFixed(2) + " евро"); 

var rouble = prompt("Введите сумму в рублях: ");
var euro = 82.68; //сегодняшний курс евро
var Itog = rouble / dollar; 
var Itog_1 = rouble / euro; //вычисление количества рублей в евро
alert("Итого: " + Itog.toFixed(2) + " долларов" + "\nИтого: " + Itog_1.toFixed(2) + " евро"); 
