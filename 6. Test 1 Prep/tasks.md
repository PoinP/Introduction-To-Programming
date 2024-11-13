# Test 1 Prep Tasks

## Задача 0
Да се напише функция, която приема масив от `n` на брой естествени числа от 0 до 1023. `(n <= 2048)`
Задачата на тази функция е да сортира елементите на подадения масив. Изкарайте сортирания масив на конзолата.

<details><summary><b>Solution</b></summary> 
<p>

```cpp
void sortArray(unsigned int arr[], unsigned size) 
{
	const unsigned numbersRange = 1024;
	unsigned numbersHeatMap[numbersRange] { 0 };

	for (unsigned i = 0; i < size; i++)
	{
		unsigned currentNum = arr[i];
		numbersHeatMap[currentNum] += 1;
	}

	unsigned counter = 0;
	for (unsigned currNum = 0; currNum < numbersRange; currNum++)
	{
		for (unsigned repeat = 0; repeat < numbersHeatMap[currNum]; repeat++)
		{
			arr[counter] = currNum;
			counter += 1;
		}
	}
}
```

</p>
</details>

## Задача 1
Напишете компресираща функция, която приема произволно 64 битово естествено число. Компресиращата функция трябва да върне компресиранатa версия на подаденото число. В подаденото число не се очаква да фигурира цифрата `0`.

> Във входа не се очаква да има повече от 9 последователни цифири 

*Пояснение*: Компресията работи по следния начин: За всяка поредица от последователни цифри се записва първо цифрата, която се повтаря и след това броя пъти в които се повтаря. Във примерните вход и изход в компресираният резултат 3 се повтаря 6 пъти, 4 - 2 пъти, 5 - 1 път и така нататък

```
Вход:
333333445699

Изход:
3642516192
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
unsigned long long reverseNum(unsigned long long num)
{
	unsigned long long reversedNum = 0;

	while (num > 0)
	{
		unsigned lastDigit = num % 10;
		reversedNum = (reversedNum * 10) + lastDigit;
		num /= 10;
	}

	return reversedNum;
}

unsigned countRepeatingNums(unsigned long long num, unsigned digit) 
{
	unsigned counter = 0;

	while (num % 10 == digit)
	{
		counter += 1;
		num = num / 10;
	}

	return counter;
}

unsigned power(unsigned base, unsigned power)
{
	unsigned result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= base;
	}

	return result;
}

unsigned long long compressNum(unsigned long long num)
{
	num = reverseNum(num);
	unsigned long long compressedNum = 0;

	while (num > 0)
	{
		unsigned lastDigit = num % 10;
		unsigned lastDigitCount = countRepeatingNums(num, lastDigit);
		num /= power(10, lastDigitCount);

		unsigned occurance = lastDigit * 10 + lastDigitCount;
		compressedNum = compressedNum * 100 + occurance;
	}

	return compressedNum;
}
```

</p>
</details>

## Задача 2
Напишете програма в която се въвеждат две двойки реални координати. Всяка двойка координати представлява първо локацията по хоризонталната акциза(X Axis) и вертикалната акциза(Y Axis). Първо се въвеждат координатите за началната ни локация. След това се въвежда друга двойка координати, която обозначава определна крайна локация. Трябва да определите спрямо въведените начални и крайни координати към коя посока трябва да тръгнем (North, East, West, South, NE, NW, SE, SW) за да стигнем до крайните координати и да я изкарате на екрана. 

Ако координатите за начало и край съвпадат, да се изведе текст `"You're already there"`.

> Трябва да съществува толеранс от 0.1. Това означава, че ако началните ни координати са (0, 0), а крайните са (0.05, 0), то тогава трябва да изкараме "You're already there:

<details><summary><b>Solution</b></summary> 
<p>

```cpp
int main()
{
	float startX, startY;
	std::cin >> startX >> startY;

	float endX, endY;
	std::cin >> endX >> endY;

	bool isNorth = startY < endY && endY - startY > 0.1f;
	bool isSouth = startY > endY && startY - endY > 0.1f;
	bool isWest = startX > endX && startX - endX > 0.1f;
	bool isEast = startX < endX && endX - startX > 0.1f;

	bool isNE = isNorth && isEast;
	bool isNW = isNorth && isWest;
	bool isSE = isSouth && isEast;
	bool isSW = isSouth && isWest;

	bool isCenter = !isNorth && !isSouth && !isWest && !isEast;

	if (isCenter)
	{
		std::cout << "You're at the center!";
		return 0;
	}

	if (isNorth)
	{
		if (isNW)
		{
			std::cout << "NW";
		}
		else if (isNE)
		{
			std::cout << "NE";
		}
		else
		{
			std::cout << "N";
		}
	}
	else if (isSouth)
	{
		if (isSW)
		{
			std::cout << "SW";
		}
		else if (isSE)
		{
			std::cout << "SE";
		}
		else
		{
			std::cout << "S";
		}
	}
	else
	{
		if (isWest)
		{
			std::cout << "W";
		}
		else
		{
			std::cout << "E";
		}
	}
}
```

</p>
</details>

## Задача 3
Напишете функция, която преобразува произволно естествено 16 битово число в 64 битово двуично число с помощтта на побитови операции.

> Преобразуването на подаденото число НЕ трябва да става с помощта на оператора за модулно деление '%'

<details><summary><b>Solution</b></summary> 
<p>

```cpp
unsigned long long convertToBinary(unsigned short num)
{
	unsigned long long binaryNum = 0;
	unsigned power = 1;

	while (num > 0)
	{
		unsigned lastDigit = num & 1;
		num = num >> 1;
		binaryNum = binaryNum + lastDigit * power;
		power *= 10;
	}

	return binaryNum;
}
```

</p>
</details>

## Задача 4
Направете функция, която приема 64-битово двуично число, както и 8-битово естествено число. Тази функция трябва да връща колко на брой пъти 8-битовото естествено число се съдържа в подаденото двуично число. За целта изпозвайте функцията от предходаната задача. Едно срещане не се препокрива с други срещания.
Това означава, че в по-долния пример 7(111) се среща точно 2 пъти. Ведънъж в началото и веднъж в средата.
Ако входинте бинарно число беше равно на 11100111111, то тогава щеше да се среща 3 пъти.

```
Вход:
11100111100 7

Изход:
2 
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

unsigned countBinaryOccurances(unsigned long long binaryBase, unsigned short num)
{
	unsigned long long binaryNum = convertToBinary(num);
	unsigned binaryNumDigitsCount = std::log10(binaryNum) + 1; // Cool way to find digits count
	unsigned long long binaryNumMask = power(10, binaryNumDigitsCount); // Using the function from the task above

	unsigned occurancesCount = 0;
	while (binaryBase > 0)
	{
		if (binaryBase % binaryNumMask == binaryNum)
		{
			occurancesCount += 1;
			binaryBase /= binaryNumMask;
		}
		else
		{
			binaryBase /= 10;
		}
	}

	return occurancesCount;
}
```

</p>
</details>