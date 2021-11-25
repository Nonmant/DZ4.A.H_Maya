# H. Расшифровка письменности Майя
https://contest.yandex.ru/contest/27665/problems/H/

Ограничение времени\
1 секунда\
Ограничение памяти\
64Mb\
Ввод\
стандартный ввод или input.txt\
Вывод\
стандартный вывод или output.txt

Расшифровка письменности Майя оказалась более сложной задачей, чем предполагалось ранними исследованиями. На протяжении более чем двух сотен лет удалось узнать не так уж много. Основные результаты были получены за последние 30 лет.

Письменность Майя основывается на маленьких рисунках, известных как значки, которые обозначают звуки. Слова языка Майя обычно записываются с помощью этих значков, которые располагаются рядом друг с другом в некотором порядке.

Одна из проблем расшифровки письменности Майя заключается в определении этого порядка. Рисуя значки некоторого слова, писатели Майя иногда выбирали позиции для значков, исходя скорее из эстетических взглядов, а не определенных правил. Это привело к тому, что, хотя звуки для многих значков известны, археологи не всегда уверены, как должно произноситься записанное слово.

Археологи ищут некоторое слово W. Они знают значки для него, но не знают все возможные способы их расположения. Поскольку они знают, что Вы приедете на IOI ’06, они просят Вас о помощи. Они дадут Вам g значков, составляющих слово W, и последовательность S всех значков в надписи, которую они изучают, в порядке их появления. Помогите им, подсчитав количество возможных появлений слова W.

Задание Напишите программу, которая по значкам слова W и по последовательности S значков надписи подсчитывает количество всех возможных вхождений слова W в S, то есть количество всех различных позиций идущих подряд g значков в последовательности S, которые являются какой-либо перестановкой значков слова W .

## Формат ввода

1 ≤ g ≤ 3 000, g – количество значков в слове W\
g ≤ |S| ≤ 3 000 000 где |S| – количество значков в последовательности S\
На вход программы поступают данные в следующем формате:\
СТРОКА 1: Содержит два числа, разделенных пробелом – g и |S|. СТРОКА 2: Содержит g последовательных символов, с помощью которых записывается слово W . Допустимы символы: ‘a’-‘z’ и ‘A’-‘Z’; большие и маленькие буквы считаются различными. СТРОКА 3: Содержит |S| последовательных символов, которые представляют значки в надписи. Допустимы символы: ‘a’-‘z’ и ‘A’-‘Z’; большие и маленькие буквы считаются различными.

## Формат вывода
Единственная строка выходных данных программы должна содержать количество возможных вхождений слова W в S.

## Пример
Ввод\
4 11\
cAda\
AbrAcadAbRa

Вывод\
2
