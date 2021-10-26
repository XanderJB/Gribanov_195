var a = prompt("Enter 1st number: ");
var b = prompt("Enter 2nd number: ");
a = parseInt(a);
b = parseInt(b);

c = a + b;
alert ("Сумма чисел равна: " + c);

c = a - b;
alert ("Разность чисел равна: " + c);

c = a * b;
alert ("Произведение чисел равно: " + c);

c = a / b;
alert ("Частное чисел равно: " + c.toFixed(2));

c = (a + b) / 2;
alert ("Среднее арифметическое чисел равно: " + c);