# String Tasks

## Задача 0
Две изречения са анаграми едно на друго, ако съдържат еднакъв брой букви (английски) и всяка буква от едното изречение се среща еднакъв брой пъти и в двете изречения. Не правим разлика между главни и малки английски букви. Напишете функция, която по два символни низа, съдържащи английски букви и евентуално интервали, проверява дали двата низа са анаграми един на друг. 
   
```
Примерен вход:
"Astronomer" 
"Moon starer"
Примерен изход: True

Примерен вход:
"A B B A"
"baba"
Примерен изход:
YES
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
bool isLetter(char character)
{
	return character >= 'A' && character <= 'Z'
		|| character >= 'a' && character <= 'z';
}

char toLower(char character)
{
	if (character >= 'A' && character <= 'Z')
		return character + 'a' - 'A';

	return character;
}

void countOccurances(const char* string, unsigned heatMap[])
{
	if (!string)
		return;

	while (*string != '\0')
	{
		if (isLetter(*string))
		{
			unsigned letterIndex = toLower(*string) - 'a';
			heatMap[letterIndex] += 1;
		}
		string += 1;
	}
}

bool isAnagram(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return false;

	const unsigned short ALPHABET_COUNT = 26;
	unsigned str1Heatmap[ALPHABET_COUNT]{};
	unsigned str2Heatmap[ALPHABET_COUNT]{};

	countOccurances(str1, str1Heatmap);
	countOccurances(str2, str2Heatmap);

	for (size_t i = 0; i < ALPHABET_COUNT; i++)
	{
		if (str1Heatmap[i] != str2Heatmap[i])
			return false;
	}

	return true;
}

int main()
{
	bool result = isAnagram("A B BC A", "baba");
	std::cout << result;
}

```

</p>
</details>

## Задача 1
Напишете фунция, която обръща думите в даден низ. Под дума ще разбираме всяка последователност от малки или главни английски букви. Например "evil rats" да се преобразува в "live star".
Функцията да не променя подадения низ, а да връща нов, за който да заделя динамична памет.

```
Примерен вход: evil rats
Примерен изход: live star
```

```
Примерен вход: Step on no pets
Примерен изход petS no on step
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
bool isLetter(char symbol)
{
	return (symbol >= 'a' && symbol <= 'z')
		|| (symbol >= 'A' && symbol <= 'Z');
}

unsigned getWordLength(const char* string) 
{
	if (!string)
		return 0;

	unsigned wordLength = 0;
	while (isLetter(*string))
	{
		wordLength += 1;
		string += 1;
	}

	return wordLength;
}

char* getWord(const char* string, unsigned wordLength) 
{
	if (wordLength == 0)
		return nullptr;

	char* word = new char[wordLength + 1];

	char* wordIter = word;
	while (isLetter(*string)) {
		*wordIter = *string;
		wordIter += 1;
		string += 1;
	}

	*wordIter = '\0';

	return word;
}

void fillNonLetterCharacters(char* destination, const char*& source) 
{
	if (!source || !destination || *source == '\0')
		return;
	
	while (*destination) 
	{
		destination += 1;
	}

	while (!isLetter(*source) && *source) {
		*destination = *source;
		destination += 1;
		source += 1;
	}

	*destination = '\0';
}

void reverseString(char* string) 
{
	unsigned stringSize = strlen(string);
	unsigned reverseIter = stringSize - 1;

	for (unsigned i = 0; i < stringSize / 2; i++) 
	{
		char temp = string[i];
		string[i] = string[reverseIter - i];
		string[reverseIter - i] = temp;
	}
}

char* reverseWordsInString(const char* string)
{
	if (!string)
		return nullptr;

	unsigned originalStringLength = strlen(string);
	char* reversedString = new char[originalStringLength + 1];
	reversedString[0] = '\0';

	fillNonLetterCharacters(reversedString, string);
	while (*string)
	{
		unsigned wordLength = getWordLength(string);
		char* word = getWord(string, wordLength);
		reverseString(word);
		strcat(reversedString, word);
		delete[] word;

		string += wordLength;
		fillNonLetterCharacters(reversedString, string);
	}

	reversedString[originalStringLength] = '\0';
	return reversedString;
}

int main() 
{
	char* str = reverseWordsInString("evil Rats");
	std::cout << str;
    delete[] str;
}
```

</p>
</details>

## Задача 2
Дума ще наричаме последователност от английски букви (главни или малки). Изречение ще наричаме последователност от думи, разделени с произволни разделители, различни от английски букви (напр. интервал, тире и т.н.)
Напишете функция, която по дадено изречение `s` и дадена дума `w` намира първата дума в `s`, която започва с първата буква на `w`, след което намира дума, започваща с втората буква на `w` и намираща се надясно от първата намерена дума и т.н. Накрая функцията да конструира изречение от намерените думи, в което те са разделени с интервали. За новото изречение да бъде заделена динамична памет. Ако за дадена буква не бъде намерена дума, процесът да се прекратява и да се връща до момента полученото изречение.

```
Примерен вход: 
But in my opinion, he is not lazy. He is working hard and smart at the same time.
hilasyt

Примерен изход:
he is lazy and smart
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
bool isLetter(char symbol)
{
	return (symbol >= 'a' && symbol <= 'z')
		|| (symbol >= 'A' && symbol <= 'Z');
}

unsigned getWordLength(const char* string) 
{
	if (!string)
		return 0;

	unsigned wordLength = 0;
	while (isLetter(*string))
	{
		wordLength += 1;
		string += 1;
	}

	return wordLength;
}

char* getWord(const char* string, unsigned wordLength) 
{
	if (wordLength == 0)
		return nullptr;

	char* word = new char[wordLength + 1];

	char* wordIter = word;
	while (isLetter(*string)) {
		*wordIter = *string;
		wordIter += 1;
		string += 1;
	}

	*wordIter = '\0';

	return word;
}

char toLower(char character)
{
	if (character >= 'A' && character <= 'Z')
		return character += ('a' - 'A');

	return character;
}

void skipWord(const char*& string)
{
	if (!string || !*string)
		return;

	while (*string && isLetter(*string))
	{
		string += 1;
	}
}

void skipNonLetters(const char*& string)
{
	if (!string || !*string)
		return;

	while (*string && !isLetter(*string))
	{
		string += 1;
	}
}

void skipToNextWord(const char*& string) 
{
	skipWord(string);
	skipNonLetters(string);
}

char* combineCluster(const char* const* wordCluster, unsigned clusterSize)
{
	if (clusterSize == 0)
		return strcpy(new char[1], "");

	unsigned totalLength = 0;
	for (unsigned i = 0; i < clusterSize; i++)
	{
		totalLength += strlen(wordCluster[i]);
	}
	totalLength += clusterSize - 1;

	char* combinedCluster = new char[totalLength + 1];
	*combinedCluster = '\0';

	for (unsigned i = 0; i < clusterSize; i++)
	{
		strcat(combinedCluster, wordCluster[i]);

		if (i + 1 < clusterSize)
			strcat(combinedCluster, " ");
	}

	return combinedCluster;
}

char* constructSentenceFromWord(const char* originalSentence, const char* word)
{
	if (!originalSentence || !word)
		return nullptr;

	unsigned wordSize = strlen(word);

	char** wordCluster = new char* [wordSize];
	unsigned wordsInCluster = 0;
	
	skipNonLetters(originalSentence);
	while (*originalSentence && *word && wordsInCluster < wordSize)
	{
		if (toLower(*originalSentence) == toLower(*word))
		{
			unsigned wordLength = getWordLength(originalSentence);
			wordCluster[wordsInCluster] = getWord(originalSentence, wordLength);
			wordsInCluster += 1;
			
			word += 1;
			originalSentence += wordLength;
		}

		skipToNextWord(originalSentence);
	}

	char* combinedCluster = combineCluster(wordCluster, wordsInCluster);

	for (unsigned i = 0; i < wordsInCluster; i++)
	{
		delete[] wordCluster[i];
	}
	delete[] wordCluster;

	return combinedCluster;
}

int main()
{
	char* text = constructSentenceFromWord("But in my opinion, he is not lazy. He is working hard and smart at the same time.", "bhilasyt");
	std::cout << text;
    delete[] text;
}
```

</p>
</details>

## Задача 3
Изречение ще наричаме символен низ, състоящ се от думи, съдържащи единствено английски букви (главни или малки), разделени с интервал. Сортирано изречение ще наричаме изречение, в което думите са подредени лексикографски в нарастващ ред, без да се прави разлика между главни и малки букви.
Да се напише функция, която слива две подадени сортирани изречения, образувайки ново сортирано изречение. За новия низ да бъде заделена динамична памет.

```
Примерен вход: 
He is there
not yet

Примерен изход:
He is not there yet
```

<details><summary><b>Solution</b></summary> 
<p>

```cpp
bool isLetter(char character)
{
	return character >= 'A' && character <= 'Z'
		|| character >= 'a' && character <= 'z';
}

unsigned getWordLength(const char* string)
{
	if (!string || *string == '\0')
		return 0;

	unsigned wordLength = 0;
	while (*string != '\0' && isLetter(*string))
	{
		wordLength += 1;
		string += 1;
	}

	return wordLength;
}


char* getWord(const char* string)
{
	unsigned wordLength = getWordLength(string);

	if (wordLength == 0)
		return nullptr;

	char* word = new char[wordLength + 1];
	char* wordIter = word;

	while (*string != '\0' && isLetter(*string))
	{
		*wordIter = *string;
		wordIter += 1;
		string += 1;
	}
	*wordIter = '\0';

	return word;
}

char* mergeSortedStrings(const char* str1, const char* str2)
{
	if (!str1 && !str2)
		return nullptr;

	if (!str1)
		return strcpy(new char[strlen(str2) + 1], str2);

	if (!str2)
		return strcpy(new char[strlen(str1) + 1], str1);
		
	unsigned str1Len = strlen(str1);
	unsigned str2Len = strlen(str2);
	char* mergedStrings = new char[str1Len + 1 + str2Len + 1];
	*mergedStrings = '\0';

	while (*str1 != '\0' && *str2 != '\0')
	{
		char* str1Word = getWord(str1);
		char* str2Word = getWord(str2);
		int result = strcmp(str1Word, str2Word);

		if (result < 1) 
		{
			strcat(mergedStrings, str1Word);
			strcat(mergedStrings, " ");
			str1 += strlen(str1Word);

			if (*str1 == ' ')
				str1 += 1;

			delete[] str1Word;
			str1Word = getWord(str1);
		}
		else
		{
			strcat(mergedStrings, str2Word);
			strcat(mergedStrings, " ");
			str2 += strlen(str2Word);

			if (*str2 == ' ')
				str2 += 1;

			delete[] str2Word;
			str2Word = getWord(str2);
		}
	}

	if (*str1 == '\0')
		strcat(mergedStrings, str2);
	else
		strcat(mergedStrings, str1);

	return mergedStrings;
}

int main()
{
	char* merged = mergeSortedStrings("He is there", "not yet");
	std::cout << merged;
	delete[] merged;
}
```

</p>
</details>

## Задача 4
Напишете функция, която приема текст и пресмята средната дължина на думите (броя букви, разделен на броя на думите). Изреченията в текста завършват с един от следните символи: точка `.`, удивителна `!` и въпросителна `?` 
> Вземете под внимание, че един текст може да има няколко спейса един след друг.

<details><summary><b>Solution</b></summary> 
<p>

```cpp
double getAverageWordLength(const char* string)
{
	int iter = 0;
	int charCount = 0;
	int wordCount = 0;

	bool isInWord = false;

	while (string[iter] != '\0')
	{
		bool isAtSymbol = string[iter] == '.' || string[iter] == '!' || string[iter] == '?' || string[iter] == ' ';
		bool isAtLetter = string[iter] >= 'A' && string[iter] <= 'Z' || string[iter] >= 'a' && string[iter] <= 'z';
		bool isAtEndOfString = string[iter + 1] == '\0';

		if (isAtLetter)
		{
			isInWord = true;
			charCount++;
		}
		
		if (isAtSymbol && isInWord || isAtEndOfString)
		{
			wordCount++;
			isInWord = false;
		}

		iter++;
	}

	return (double)charCount / wordCount;
}
```

</p>
</details>