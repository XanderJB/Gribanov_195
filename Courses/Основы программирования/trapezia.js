var baseLength_1 = prompt("Введите длину основания трапеции а: "); //пользователь вводит длину первого основания трапеции
var baseLength_2 = prompt("Введите длину основания трапеции b: "); //пользователь вводит длину второго основания трапеции
var trapezoidHeight = prompt("Введите высоту трапеции h: "); //пользователь вводит высоту трапеции

baseLength_1 = parseInt(baseLength_1); //мы передаем в переменные a, b, h численные значения
baseLength_2 = parseInt(baseLength_2);
trapezoidHeight = parseInt(trapezoidHeight);

var trapezoidArea = trapezoidHeight*(baseLength_1+baseLength_2)/2; //мы задаем компьютеру формулу, по которой он должен посчитать площадь трапеции
alert("Площадь трапеции равна " + trapezoidArea); //вывод значения площади трапеции
