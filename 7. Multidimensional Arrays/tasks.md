# Multidimensional Arrays Tasks

## Задача 0
Една редица от естествени числа ще наричаме зигзагообразна нагоре, ако за елементите й са изпълняват условията:
N1 < N2 > N3 < N4 > N5 <..
Направете функция isZigZag, която проверява дали въведени в едномерен масив редица от числа изпълняват горните изисквания.

```
Примерен вход: 
6
1 3 2 4 3 7
Примерен изход: YES
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
#include <iostream>

void enterArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> numbers[i];
	}
}

bool isZigZag(int numbers[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (i % 2 != 0)
		{
			if (numbers[i - 1] >= numbers[i]) 
            return false;
		}
		else
		{
			if (numbers[i - 1] <= numbers[i]) 
            return false;
		}
	}

	return true;
}

int main()
{
	const int ARRAY_SIZE = 100;
	int numbers[ARRAY_SIZE];
	int userSize;

	std::cout << "How many numbers do you want to enter[1-100]: ";

	do
	{
		std::cin >> userSize;
	} while (userSize < 1 || userSize > 100);

	std::cout << "Enter the array's elements: " << std::endl;
	enterArray(numbers, userSize);

	std::cout << "Is zigzag: " << (isZigZag(numbers, userSize) ? "YES" : "NO") << std::endl;
}
```

</p>
</details>

## Задача 1
Да се направи функция reverse, чрез която предварително въведени n естествени числа от интервала [0..5000] в едномерен масив се разменят местата на елементите му.
Така 1-вият става последен а последният елемент 1-ви; 2-рият елемент става предпоследен, а предпоследният елемент става 2-ри и т.н.
Функцията да илюстрира обхождане на масив при извършване размяна стойностите на отделните елементи.

```
Примерен вход: 
7 
1 2 4 3 5 6 7 
Примерен изход: 7, 6, 5, 3, 4, 2, 1
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
#include <iostream>

void reverseArray(int arr[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
      // Swapping elements
		arr[i] ^= arr[size - i - 1];
		arr[size - i - 1] ^= arr[i];
		arr[i] ^= arr[size - i - 1];
	}
}

void enterArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> numbers[i];
	}
}

void printArray(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int main()
{
	const int ARRAY_SIZE = 5000;
	int numberArray[ARRAY_SIZE];
	int userSize;

	std::cout << "How big do you want the array to be[0 - 5000]: ";

	do
	{
		std::cin >> userSize;
	} while (userSize < 0 || userSize > 5000);

   enterArray(numberArray, userSize);
	std::cout << std::endl;

	reverseArray(numberArray, userSize);
	printArray(numberArray, userSize);
}
```

</p>
</details>

## Задача 2
Да се направи функция onlyOdd, чрез която се въвежда естествено число N от интервала [5..25].
Да се въведат N броя двуцифрени естествени числа.
Функцията да използва само един масив и да илюстрира алгоритъм за изтриване на елемент при работа с масив.
Въведените в масива числа се разглеждат като четни и нечетни по следния начин: 
- всяко четно число се изтрива 
- нечетните числа съхраняват стойността си и съответната относителна позиция в масива.

```
Примерен вход: 
11 
12 45 33 26 32 47 91 92 72 14 62 
Примерен изход: 45, 33, 47, 91

```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
#include <iostream>

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void enterArray(int numbers[], int size)
{
    std::cout << "Enter the array's elements: " << std::endl;

    for (int i = 0; i < size; i++)
    {
        do
        {
            std::cin >> numbers[i];
        } while (numbers[i] < 10 || numbers[i] > 99);
    }

    std::cout << std::endl;
}

void onlyOdd(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            for (int j = 0; j < size - i; j++)
            {
                numbers[i + j] = numbers[i + j + 1];
            }

            size--;
            i--;
        }
    }

    printArray(numbers, size);
}

int main()
{
    const int ARRAY_SIZE = 25;
    int numbers[ARRAY_SIZE];
    int userSize;

    std::cout << "Please enter a size for the array[5 - 25]: ";

    do
    {
        std::cin >> userSize;
    } while (userSize < 5 || userSize > 25);

    std::cout << "Please enter only 2-digit numbers: ";
    enterArray(numbers, userSize);

    onlyOdd(numbers, userSize);
}
```

</p>
</details>

## Задача 4
Въведете двумерна матрица, намерете сумата на всеки ред от матрицата(Решете с функция).

<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>

## Задача 5
По въведена двумерна квадратна матрица намерете сумата на двата диагонала(Решете с функция).

<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>

## Задача 6
Да се напише функция, която извежда матрица, получена от въведената, като всеки нейн елемент е увеличен с 10.

<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>

## Задача 7
Да се напише функция, която намира и извежда минималния и максималния елемент в матрицата.

<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>

## Задача 8 !!!!
Да се напише функция, която намира и извежда ***сумата*** от елементите на **квадратна матрица** на:

   * всеки ред
   * всеки стълб
   * главния диагонал
   * под главния диагонал
   * над главния диагонал
   * вторичния диагонал
   * под вторичния диагонал
   * над вторичния диагонал
   
<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>

## Задача 9
Да се напише функция, която въвежда цяло число х, да се провери дали х е **елемент на матрицата**, и ако е - да се изведе позицията на елемнта в матрицата и елемента да се умножи по 10, а ако не е елемент на матрицата да се изведе подходящо съобщение.

<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>

## Задача 10
Да се напише функция, която въвежда едномерен масив от целочислени числа и да ги сортира във възходящ ред.

### За задачите за сортиране може да ползвате един от следните алгоритми за сортиране: Bubble sort, insertion sort, selection sort.

<details><summary><b>Solution</b></summary> 
<p>

```cpp
```

</p>
</details>