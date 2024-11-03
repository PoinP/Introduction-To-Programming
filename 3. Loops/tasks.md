# Tasks

## Task 0
По въведено число(месец) от конзолата, изкарайте сезона за подадения месец.

```
Примерен вход: 1
Примерен изход: Winter
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
    unsigned month;
    std::cin >> month;
    
    switch (month)
    {
    case 12: case 1: case 2: std::cout << "Winter" << std::endl; break;
    case 3: case 4: case 5: std::cout << "Spring" << std::endl; break;
    case 6: case 7: case 8: std::cout << "Summer" << std::endl; break;
    case 9: case 10: case 11: std::cout << "Autumn" << std::endl; break;
    
    default: std::cout << "There is no such month" << std::endl; break;
    }
}

```

</p>
</details>

## Task 1

По даден месец и година изведете броя дни от месеца.
**Внимавайте с високосните години!**

```
Примерн вход: 2 2024
Примерен изход 29
```
<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
	unsigned month, year; // unsigned == unsigned int;
    bool isLeap;

	std::cout << "Please enter the month and year: ";
	std::cin >> month >> year;

    switch (month)
    {
    case 1: case 3: case 5:
    case 7: case 8: case 10:
    case 12:
        std::cout << 31;
        break;
    case 4: case 6: case 9:
    case 11:
        std::cout << 30;
        break;
    case 2:
        isLeap = ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0);
        std::cout << (isLeap ? 29 : 28);
        break;
    default:
        std::cout << "Invalid month!";
        break;
    }
}

```
</p>
</details>

## Task 2 
Да се напише програма, която чете от клавиатурата `n` числа и извежда най-голямото отрицателно число.

```
Примерен вход: 8 2 3 4 -5 -4 3 -2 3
Примерен изход: -2
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
    unsigned n;
	int userInput;
    int maxNegative = INT_MIN;

	std::cout << "How many numbers do you want to enter: ";
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> userInput;
		
		if (userInput < 0 && userInput > maxNegative)
		{
			maxNegative = userInput;
		}
	}

	std::cout << maxNegative;


	// Second version (Does not need the knowledge of INT_MIN)

	//unsigned n;
	//int userInput;
	//int maxNegative = 0; <------ Note that we set maxNegative as 0

	//std::cout << "How many numbers do you want to enter: ";
	//std::cin >> n;

	//for (int i = 0; i < n; i++)
	//{
	//	std::cin >> userInput;

	//	if (maxNegative >= 0 && userInput < 0) <------ And check if the user input is negative, then we can set an actual max negative value to our variable. We can continue our checks from there!
	//	{
	//		maxNegative = userInput;
	//	}

	//	if (userInput < 0 && userInput > maxNegative)
	//	{
	//		maxNegative = userInput;
	//	}
	//}

	//std::cout << maxNegative;
}

```
</p>
</details>

## Task 3 
От клавиатурата се въвеждат произволен брой числа. Намерете сбора на всички числа до въвеждането на 0.

```
Примерен вход: 1 2 3 0 5
Примерен изход: 6 
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
    int sum = 0;
    int userInput;

    std::cout << "Enter as many integers as you like! Enter '0' to break the loop!\n";

    do
    {
        std::cin >> userInput;
        sum = sum + userInput;
    } while (userInput != 0);

    std::cout << sum;
}

```
</p>
</details>

## Task 4 
От клавиатурата се въвежда естествено число. Намерете сбора на цифрите му.

```
Примерен вход: 5550
Примерен изход: 15
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
    unsigned userNumber;
    unsigned sum = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> userNumber;

    while (userNumber > 0)
    {
        sum = sum + userNumber % 10;
        userNumber = userNumber / 10;
    }

    std::cout << "The sum of the digits is " << sum;
}

```
</p>
</details>

## Task 5
Да се въведе някое естествено число от клавиатурата и да се изведе неговото представяне в
произволна произволна бройна система (от двоична до десетична).

```
Примерен вход: 6
Примерен изход: 110

Примерен вход: 76
Примерен изход: 1001100
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
	const unsigned base = 8;

	unsigned short userInput;
	std::cin >> userInput;

	unsigned long long binaryNum = 0;
	unsigned power = 1;

	while (userInput > 0)
	{
		unsigned digit = userInput % base;
		binaryNum = binaryNum + power * digit;
		power *= 10;
		userInput /= base;
	}

	std::cout << binaryNum;
}

```
</p>
</details>

## Task 6
Да се въведе произволно естествено число от конзолата и да се обърнат цифирте му в нова променлива

```
Примерен вход: 1234
Примерен изход: 4321

Примерен вход: 663344
Примерен изход: 443366
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
	unsigned userInput;
    std::cin >> userInput;

    unsigned reversedNum = 0;

    while (userInput > 0)
    {
        reversedNum = reversedNum * 10 + userInput % 10;
        userInput /= 10;
    }

    std::cout << reversedNum;
}

```
</p>
</details>

## Task 7
Да се провери дали едно въведено число е палиндром

```
Примерен вход: 1234
Примерен изход: false

Примерен вход: 663366
Примерен изход: true
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp

#include <iostream>

int main()
{
	unsigned userInput;
    std::cin >> userInput;

    unsigned reversedNum = 0;
    unsigned originalNum = userInput;

    while (userInput > 0)
    {
        reversedNum = reversedNum * 10 + userInput % 10;
        userInput /= 10;
    }

    std::cout << std::boolalpha << (originalNum == reversedNum);
}

```
</p>
</details>

## Task 8
Да се провери дали дадено есетствено число е перфектно. 
Перфектно е такова число, което е равно на сбора от делителите си. Пример 28 = (1 + 2 + 4 + 7 + 14)
> Бонус: Намерете първите 2 перфектни числа

```
Примерен вход: 6
Примерен изход: true

Примерен вход: 200
Примерен изход: false

Примерен вход: 28
Примерен изход: true
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
// No solution yet :)
```
</p>
</details>

## Task 9
Да се напише програма, която проверява дали дадено число е просто или не.
> Бонус: Изкарайте първите 10 прости числа

```
Примерен вход: 6
Примерен изход: true

Примерен вход: 200
Примерен изход: false

Примерен вход: 28
Примерен изход: true
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
// No solution yet :)
```
</p>
</details>