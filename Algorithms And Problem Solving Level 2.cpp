#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//general functions

int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        if (message == "default")
            cout << "please enter a positive number :\n";
        else
            cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

float ReadNumber(string massege)
{
    cout << massege;
    float number;
    cin >> number;
    return number;
}

string ReadText(string massage)
{
    cout << massage;
    string text;
    getline(cin, text);
    return text;
}

bool CheckPrime(int x)
{
    int m = round(x / 2);
    for (int i = 2; i <= m; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void SwapNumber(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

enum enOddEven { odd, even };

enOddEven CheckOddEven(int number)
{
    if (number % 2 == 0)
        return even;
    else
        return odd;
}

float MyAbs(float number)
{
    if (number < 0)
        return number * -1;
    else
        return number;
}

float GetFraction(float number)
{
    return number - (int)number;
}

float MyRound(float number)
{
    int int_part = (int)number;
    float faraction_part = GetFraction(number);
    if (number >= 0)
        if (faraction_part >= 0.5)
            return int_part + 1;
        else
            return int_part;
    else if (faraction_part <= -0.5)
        return int_part - 1;
    else
        return int_part;
}

float MyFloor(float number)
{
    if (number >= 0)
        return (int)number;
    else
        return (int)number - 1;
}

float MyCeil(float number)
{
    if (number >= 0)
    {
        if (abs(GetFraction(number)) > 0)
            return (int)number + 1;
        else
            return (int)number;
    }
    else
        return (int)number;
}

float power(float number, float power)
{
    float result = 1;
    for (int i = 1; i <= power; i++)
        result *= number;
    return result;
}

float MySqrt(float number)
{
    return pow(number, 0.5);
}


//random functions

int RandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

enum enTypeOfChar { small_letter, capital_letter, special_chars, digit };

char Randomcahr(enTypeOfChar type)
{
    switch (type)
    {
    case enTypeOfChar::small_letter:
        return RandomNumber(97, 122);
    case enTypeOfChar::capital_letter:
        return RandomNumber(65, 90);
    case enTypeOfChar::special_chars:
        return RandomNumber(33, 47);
    case enTypeOfChar::digit:
        return RandomNumber(48, 57);
    }
}

string GetRandomWord(enTypeOfChar type, int wordlength)
{
    string word = "";
    for (int i = 1; i <= wordlength; i++)
        word += Randomcahr(type);
    return word;
}

string GetRandomKey()
{
    string key = "";
    for (int i = 1; i <= 4; i++)
    {
        key += GetRandomWord(enTypeOfChar::capital_letter, 4);
        if (i == 4)
            continue;
        key += "-";
    }
    return key;
}

void GetRandomKeys(int number)
{
    cout << endl;
    for (int i = 1; i <= number; i++)
        cout << "key [" << i << "] : " << GetRandomKey() << endl;
}


//array functions

void PrintArray(int arr[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void PrintArrayOfString(string arr[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        cout << "Array[" << i + 1 << "] : " << arr[i] << endl;
    cout << endl;
}

void FillArrayWithRandomNumbers(int arr[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arr[i] = RandomNumber(1, 100);
}

int NumberHowManyTimesRepetedInArray(int arr[], int arr_length, int serched_number)
{
    int repeted = 0;
    for (int i = 0; i <= arr_length - 1; i++)
    {
        if (arr[i] == serched_number)
            repeted++;
    }
    return repeted;
}

void ReadArray(int arr[], int& arr_length)
{
    arr_length = ReadPositiveNumber("how many element you want in the array (max 100) :\n");

    cout << "enter array element: \n\n";
    for (int i = 0; i <= arr_length - 1; i++)
    {
        cout << "element [" << i + 1 << "]" << ": ";
        cin >> arr[i];
        cout << endl;
    }
}

int MaxNumberInArray(int arr[], int arr_length)
{
    int max = arr[0];
    for (int i = 0; i <= arr_length - 1; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int MinNumberInArray(int arr[], int arr_length)
{
    int min = arr[0];
    for (int i = 0; i <= arr_length - 1; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int SumNumberInArray(int arr[], int arr_length)
{
    int sum = 0;
    for (int i = 0; i <= arr_length - 1; i++)
        sum += arr[i];
    return sum;
}

float AverageOfArray(int arr[], int arr_length)
{
    return (float)SumNumberInArray(arr, arr_length) / arr_length;
}

void CopyArray(int arr_source[], int arr_destination[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arr_destination[i] = arr_source[i];
}

void CopyPrimeNumberFromArrayToAnotherArray(int arr_source[], int arr_destination[], int arr_source_length, int& arr_destination_length)
{
    for (int i = 0; i <= arr_source_length - 1; i++)
    {
        if (CheckPrime(arr_source[i]))
        {
            arr_destination[arr_destination_length] = arr_source[i];
            arr_destination_length++;
        }
    }
}

void Sum2Array(int arr1[], int arr2[], int arrsum[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arrsum[i] = arr1[i] + arr2[i];
}

void FillArrayFrom1ToN(int arr[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arr[i] = i + 1;
}

bool SercheElementInArray(int arr[], int arr_length, int key)
{
    for (int i = 0; i <= arr_length - 1; i++)
    {
        if (key == arr[i])
            return true;
    }
    return false;
}

void ShuffleArray(int arr[], int arr_length)
{
    int temp;
    int temparr[100];
    for (int i = 0; i <= arr_length - 1; i++)
    {
        do
        {
            temp = RandomNumber(1, arr_length);
        } while (SercheElementInArray(temparr, arr_length, temp));
        temparr[i] = temp;
    }
    CopyArray(temparr, arr, arr_length);
}

void ShuffleArray2(int arr[], int arr_length)
{
    for (int i = 1; i <= arr_length; i++)
        SwapNumber(arr[RandomNumber(0, arr_length - 1)], arr[RandomNumber(0, arr_length - 1)]);
}

void ReverseArray(int arr[], int arr2[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arr2[i] = arr[arr_length - 1 - i];
}

void FillArrayWithRandomKeys(string arr[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arr[i] = GetRandomKey();
}

int ReturnIndexOfElement(int arr[], int arr_length, int element)
{
    for (int i = 0; i <= arr_length - 1; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

bool SercheElementInArray2(int arr[], int arr_length, int key)
{
    return ReturnIndexOfElement(arr, arr_length, key) != -1;
}

void AddElementToArray(int arr2[], int& arr2_length, int add_element)
{
    arr2[arr2_length] = add_element;
    arr2_length++;
}

void UserInputNumberToArray(int arr[], int& arr_length)
{
    bool add_more;
    do
    {
        AddElementToArray(arr, arr_length, ReadNumber("please enter a number: "));
        cout << "do you want to add more numbers? (0 = no), (1 = yes): ";
        cin >> add_more;
    } while (add_more);
}

void CopyArrayUsingAddElementToArray(int arr[], int arr_length, int arr2[], int arr2_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        AddElementToArray(arr2, arr2_length, arr[i]);
}

void CopyOddNumbersToArray(int arr[], int arr_length, int arr2[], int& arr2_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
    {
        if (CheckOddEven(arr[i]) == enOddEven::odd)
            AddElementToArray(arr2, arr2_length, arr[i]);
    }
}

void CopyPrimeNumberUsingAddElementToArray(int arr[], int arr_length, int arr2[], int& arr2_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        if (CheckPrime(arr[i]))
            AddElementToArray(arr2, arr2_length, arr[i]);
}

void CopyDistinctNumbersToArray(int arr[], int arr_length, int arr2[], int& arr2_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        if (!SercheElementInArray(arr2, arr2_length, arr[i]))
            AddElementToArray(arr2, arr2_length, arr[i]);
}

bool IsPalindromeArray(int arr[], int arr_length)
{
    for (int i = 0; i <= (arr_length - 1) / 2; i++)
        if (arr[i] != arr[arr_length - 1 - i])
            return false;
    return true;
}

short CountOddNumbersInArray(int arr[], int arr_length)
{
    int c = 0;
    for (int i = 0; i <= arr_length - 1; i++)
        if (CheckOddEven(arr[i]) == enOddEven::odd)
            c++;
    return c;
}

short CountEvenNumbersInArray(int arr[], int arr_length)
{
    int c = 0;
    for (int i = 0; i <= arr_length - 1; i++)
        if (CheckOddEven(arr[i]) == enOddEven::even)
            c++;
    return c;
}

void FillArrayWithRandomNumbers_minus100_100(int arr[], int arr_length)
{
    for (int i = 0; i <= arr_length - 1; i++)
        arr[i] = RandomNumber(-100, 100);
}

int CountPositiveNumberInArray(int arr[], int arr_length)
{
    int c = 0;
    for (int i = 0; i <= arr_length - 1; i++)
        if (arr[i] > 0)
            c++;
    return c;
}

int CountNegativeNumberInArray(int arr[], int arr_length)
{
    int c = 0;
    for (int i = 0; i <= arr_length - 1; i++)
        if (arr[i] <= 0)
            c++;
    return c;
}





void PrintMultiplicationTableUpSide()
{
    cout << "\n\n\t\t\tMultiplication Table From 1 to 10\n\n";
    for (int i = 1; i <= 10; i++)
        cout << "\t" << i;
    cout << "\n-----------------------------------------------------------------------------------\n";
}

void PrintMultiplicationTableLeftSide(int i)
{
    cout << " " << i;
    if (i >= 10)
        cout << "  | ";
    else
        cout << "   | ";
}

void CalculateMultiplicationTable(int i)
{
    for (int j = 1; j <= 10; j++)
    {
        cout << "\t" << i * j;
    }
}

void PrintMultiplicationTable()
{
    PrintMultiplicationTableUpSide();

    for (int i = 1; i <= 10; i++)
    {
        PrintMultiplicationTableLeftSide(i);
        CalculateMultiplicationTable(i);
        cout << endl;
    }
}

void fun1()
{
    PrintMultiplicationTable();
}



void PrintPrimeNumbersFrom1ToN(int number)
{

    cout << "\nprime numbers from 1 to " << number << " are :\n\n";
    for (int i = 1; i <= number; i++)
    {
        if (CheckPrime(i) == true)
            cout << i << endl;
    }
}

void fun2()
{
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("please enter a positive number :\n"));
}



bool IsPerfectNumber(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return sum == number;
}

void PrintIsPerfect(int number)
{
    if (IsPerfectNumber(number))
        cout << number << " is perfect number";
    else cout << number << " is not perfect number";
}

void fun3()
{
    PrintIsPerfect(ReadPositiveNumber("please enter positive number :\n"));
}



void PrintPerfectNumbersFrom1ToN(int number)
{
    cout << "\nperfect numbers from 1 to " << number << " are :\n\n";
    for (int i = 1; i <= number; i++)
    {
        if (IsPerfectNumber(i) == true)
            cout << i << endl;
    }
}

void fun4()
{
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("please enter positive number: \n"));
}



void PrintDigits(int number)
{
    cout << endl;
    while (number > 0)
    {
        cout << number % 10 << endl;
        number = number / 10;
    }
}

void fun5()
{
    PrintDigits(ReadPositiveNumber("default"));
}



int SumOfDigits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void PrintSumOfDigits(int number)
{
    cout << "\nsum of " << number << " digits = " << SumOfDigits(number);
}

void fun6()
{
    PrintSumOfDigits(ReadPositiveNumber("default"));
}



int ReverseDigit(int number)
{
    int reversed_number = 0;
    while (number > 0)
    {
        reversed_number = reversed_number * 10 + number % 10;
        number /= 10;
    }
    return reversed_number;
}

void PrintReverseOfDigit(int number)
{
    cout << "reversed digit is:\n" << ReverseDigit(number) << endl;
}

void fun7()
{
    PrintReverseOfDigit(ReadPositiveNumber("default"));
}



int CheckFrequencyOfSearchedDigitInNumber(int number, int searched_digit)
{
    int frequency = 0;
    while (number > 0)
    {
        if (number % 10 == searched_digit)
            frequency++;
        number /= 10;
    }
    return frequency;
}

void PrintFrequencyOfDigit(int number, int searched_digit)
{
    int frequency = CheckFrequencyOfSearchedDigitInNumber(number, searched_digit);
    cout << "\ndigit " << searched_digit << " frequency is " << frequency << " time(s)\n";
}

void fun8()
{
    int number = ReadPositiveNumber("please enter the main number (as positive number) :\n");
    int searched_digit = ReadPositiveNumber("please enter one digit to check (as positive number) :\n");
    PrintFrequencyOfDigit(number, searched_digit);
}



void PrintAllDigitsFrequency(int number)
{
    int frequency;
    for (int i = 1; i <= 9; i++)
    {
        frequency = CheckFrequencyOfSearchedDigitInNumber(number, i);
        if (frequency == 0)
            continue;
        cout << "\ndigit " << i << " frequency is " << frequency << " time(s)\n";
    }
}

void fun9()
{
    PrintAllDigitsFrequency(ReadPositiveNumber("please enter the main number (as positive number) :\n"));
}



void fun10()
{
    PrintDigits(ReverseDigit(ReadPositiveNumber("default")));
}



bool IsPalindromeNumber(int number)
{
    return number == ReverseDigit(number);
}

void fun11()
{
    if (IsPalindromeNumber(ReadPositiveNumber("default")))
        cout << "\nyes, its palindrome number\n";
    else
        cout << "\nno, its not palindrome number\n";
}


void PrintInvertedNumberPattern(int number)
{
    cout << endl;
    for (int i = number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}

void fun12()
{
    PrintInvertedNumberPattern(ReadPositiveNumber("default"));
}



void PrintNumberPattern(int number)
{
    cout << "\n";
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << "\n";
    }
}

void fun13()
{
    PrintNumberPattern(ReadPositiveNumber("default"));
}


void PrintInvertedLetterPattern(int number)
{
    cout << endl;
    for (int i = 64 + number; i >= 65; i--)
    {
        for (int j = 65; j <= i; j++)
            cout << char(i);
        cout << endl;
    }
}

void fun14()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("default"));
}



void PrintLetterPattern(int number)
{
    cout << endl;
    for (int i = 65; i <= 64 + number; i++)
    {
        for (int j = 1; j <= i - 64; j++)
            cout << char(i);
        cout << endl;
    }
}

void fun15()
{
    PrintLetterPattern(ReadPositiveNumber("default"));
}



void  PrintAllWordsFromAAAToZZZ()
{
    string word;
    for (int i = 65; i <= 90; i++)
        for (int j = 65; j <= 90; j++)
            for (int t = 65; t <= 90; t++)
            {
                word = char(i);
                word += char(j);
                word += char(t);
                cout << word << endl;
                word = "";
            }
}

void fun16()
{
    PrintAllWordsFromAAAToZZZ();
}



bool SercheForPassword(string password)
{
    cout << endl;
    string word;
    int trial = 0;
    for (int i = 65; i <= 90; i++)
        for (int j = 65; j <= 90; j++)
            for (int t = 65; t <= 90; t++)
            {
                trial++;
                cout << "trail [" << trial << "] : ";
                word = char(i);
                word += char(j);
                word += char(t);
                cout << word << endl;
                if (word == password)
                {
                    cout << "\npassword is " << word << "\nfound after " << trial << " trial(s)\n";
                    return true;
                }
                word = "";
            }
    cout << "\npassword not found!\n";
    return false;
}

void fun17()
{
    SercheForPassword(ReadText("please enter 3-letter password (all capital):\n"));
}



string Encrypt_Password(string password, short encryption_key)
{
    for (int i = 0; i <= password.length(); i++)
        password[i] = char((int)password[i] + encryption_key);
    return password;
}

string Decrypt_Password(string password, short encryption_key)
{
    for (int i = 0; i <= password.length(); i++)
        password[i] = char((int)password[i] - encryption_key);
    return password;
}

void fun18()
{
    const short encryption_key = 2;

    string password = ReadText("please enter a password:\n");
    string encrypted_password = Encrypt_Password(password, encryption_key);
    string decrypted_password = Decrypt_Password(encrypted_password, encryption_key);

    cout << "\npassword before encryption : " << password;
    cout << "\npassword after encryption  : " << encrypted_password;
    cout << "\npassword after decryption  : " << decrypted_password << endl;
}



void fun19()
{
    for (int i = 1; i <= 3; i++)
        cout << RandomNumber(1, 10) << endl;
}



void fun20()
{
    cout << Randomcahr(enTypeOfChar::small_letter) << endl;
    cout << Randomcahr(enTypeOfChar::capital_letter) << endl;
    cout << Randomcahr(enTypeOfChar::special_chars) << endl;
    cout << Randomcahr(enTypeOfChar::digit) << endl;
}



void fun21()
{
    GetRandomKeys(ReadPositiveNumber("how many key you want: \n"));
}



void fun22()
{
    int arr_length;
    int arr[100];
    ReadArray(arr, arr_length);

    int serched_number = ReadPositiveNumber("\nenter the number you want to check: \n");

    cout << "\noriginal array: ";
    PrintArray(arr, arr_length);

    cout << "\n\nnumber " << serched_number << " is repeated "
        << NumberHowManyTimesRepetedInArray(arr, arr_length, serched_number) << " time(s) in the array\n";
}



void fun23()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");
    FillArrayWithRandomNumbers(arr, arr_length);
    cout << "\narray elements: ";
    PrintArray(arr, arr_length);
    cout << endl;
}



void fun24()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");
    FillArrayWithRandomNumbers(arr, arr_length);
    cout << "\narray elements: ";
    PrintArray(arr, arr_length);
    cout << "\n\nmax number is: " << MaxNumberInArray(arr, arr_length) << "\n";
}



void fun25()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");
    FillArrayWithRandomNumbers(arr, arr_length);
    cout << "\narray elements: ";
    PrintArray(arr, arr_length);
    cout << "\n\nmin number is: " << MinNumberInArray(arr, arr_length) << "\n";
}



void fun26()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\narray elements: ";
    PrintArray(arr, arr_length);

    cout << "\n\nsum of all array elements: " << SumNumberInArray(arr, arr_length) << "\n";
}



void fun27()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\narray elements: ";
    PrintArray(arr, arr_length);

    cout << "\n\naverage of all array elements: " << AverageOfArray(arr, arr_length) << "\n";
}



void fun28()
{
    int arr[100], arr2[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr, arr_length);
    CopyArray(arr, arr2, arr_length);

    cout << "\narray elements:\n";
    PrintArray(arr, arr_length);

    cout << "\narray2 elements after copying from arr:\n";
    PrintArray(arr2, arr_length);
    cout << endl;
}



void fun29()
{
    int arr[100], prime_araray[100];
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");
    int prime_array_length = 0;

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\narray elements:\n";
    PrintArray(arr, arr_length);

    CopyPrimeNumberFromArrayToAnotherArray(arr, prime_araray, arr_length, prime_array_length);

    cout << "\n\nprime numbers in the array :\n";
    PrintArray(prime_araray, prime_array_length);
    cout << endl;
}



void fun30()
{
    int arr1[100], arr2[100], arr_sum[100];
    int arr_length = ReadPositiveNumber("how many element you want in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr1, arr_length);
    FillArrayWithRandomNumbers(arr2, arr_length);
    Sum2Array(arr1, arr2, arr_sum, arr_length);

    cout << "\narray 1 elements :\n";
    PrintArray(arr1, arr_length);

    cout << "\n\narray 2 elements :\n";
    PrintArray(arr2, arr_length);

    cout << "\n\narray of sum elements:\n";
    PrintArray(arr_sum, arr_length);

    cout << endl;
}



void fun31()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter number of elements:\n");

    FillArrayFrom1ToN(arr, arr_length);

    cout << "array elements before shuffle:\n";
    PrintArray(arr, arr_length);
    cout << endl;

    ShuffleArray2(arr, arr_length);

    cout << "array elements after shuffle:\n";
    PrintArray(arr, arr_length);
    cout << endl;
}



void fun32()
{
    int arr[100], arr2[100];
    int arr_length = ReadPositiveNumber("enter element:\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "array 1:\n";
    PrintArray(arr, arr_length);
    cout << endl;
    ReverseArray(arr, arr2, arr_length);
    cout << "array 2 filled with reverse order of array 1:\n";
    PrintArray(arr2, arr_length);
}



void fun33()
{
    string arr[100];
    int arr_length = ReadPositiveNumber("enter element:\n");

    FillArrayWithRandomKeys(arr, arr_length);

    PrintArrayOfString(arr, arr_length);
}



void fun34()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter how many element you want:\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arr_length);

    int searchforthis = ReadPositiveNumber("\nplease enter a number to search for:\n");
    int index_of_element = ReturnIndexOfElement(arr, arr_length, searchforthis);

    cout << "\nnumber you are looking for is " << searchforthis << endl;

    if (index_of_element != -1)
    {
        cout << "the number found at position : " << index_of_element << endl;
        cout << "order of the number in the array is : " << index_of_element + 1 << endl;
    }
    else
        cout << "the number is not found :-(\n";
}



void fun35()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter how many element you want:\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arr_length);

    int searchforthis = ReadPositiveNumber("\nplease enter a number to search for:\n");

    cout << "\nnumber you are looking for is " << searchforthis << endl;

    if (!SercheElementInArray(arr, arr_length, searchforthis))
    {
        cout << "no, the number is not found :-(\n";
    }
    else
        cout << "yes ,the number is found :-)\n";
}



void fun36()
{
    int arr[100];
    int arr_length = 0;

    UserInputNumberToArray(arr, arr_length);

    cout << "array length: " << arr_length << endl;
    cout << "array elements: ";
    PrintArray(arr, arr_length);
}



void fun37()
{
    int arr[100], arr2[100], arr2_length = 0;
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    CopyArrayUsingAddElementToArray(arr, arr_length, arr2, arr2_length);

    cout << "\narray1 elements:\n";
    PrintArray(arr, arr_length);

    cout << "\narray2 elements after copying from array1:\n";
    PrintArray(arr2, arr_length);
}



void fun38()
{
    int arr[100], arr2[100], arr2_length = 0;
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    CopyOddNumbersToArray(arr, arr_length, arr2, arr2_length);

    cout << "\narray1 elements:\n";
    PrintArray(arr, arr_length);

    cout << "\narray2 odd numbers:\n";
    PrintArray(arr2, arr2_length);
}



void fun39()
{
    int arr[100], arr2[100], arr2_length = 0;
    int arr_length = ReadPositiveNumber("how many element you want to be filled in the array (max 100) :\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    CopyPrimeNumberUsingAddElementToArray(arr, arr_length, arr2, arr2_length);

    cout << "\narray1 elements:\n";
    PrintArray(arr, arr_length);

    cout << "\narray2 prime numbers:\n";
    PrintArray(arr2, arr2_length);
}



void FillArrayHardCoded40(int arr[], int& arr_length)
{
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 2;
    arr[5] = 5;
    arr[6] = 5;
    arr[7] = 6;
    arr[8] = 4;
    arr[9] = 2;

    arr_length = 10;
}

void fun40()
{
    int arr[100], arr_length = 0, arr2[100], arr2_length = 0;

    FillArrayHardCoded40(arr, arr_length);

    CopyDistinctNumbersToArray(arr, arr_length, arr2, arr2_length);

    cout << "\narray1 elements:\n";
    PrintArray(arr, arr_length);

    cout << "\narray2 distinct numbers:\n";
    PrintArray(arr2, arr2_length);
}



void FillArrayHardCoded41(int arr[], int& arr_length)
{
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;

    arr_length = 6;
}

void fun41()
{
    int arr[100], arr_length = 0;

    FillArrayHardCoded41(arr, arr_length);

    cout << "\narray1 elements:\n";
    PrintArray(arr, arr_length);

    if (IsPalindromeArray(arr, arr_length))
        cout << "\nyes, its palindrome array\n";
    else
        cout << "\nno, its not palindrome array\n";
}



void fun42()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter array element size:\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\narray element:\n";
    PrintArray(arr, arr_length);

    cout << "\nodd numbers count is: " << CountOddNumbersInArray(arr, arr_length) << endl;
}



void fun43()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter array element size:\n");

    FillArrayWithRandomNumbers(arr, arr_length);

    cout << "\narray element:\n";
    PrintArray(arr, arr_length);

    cout << "\neven numbers count is: " << CountEvenNumbersInArray(arr, arr_length) << endl;
}



void fun44()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter array element size:\n");

    FillArrayWithRandomNumbers_minus100_100(arr, arr_length);

    cout << "\narray element:\n";
    PrintArray(arr, arr_length);

    cout << "\npositive numbers count is: " << CountPositiveNumberInArray(arr, arr_length) << endl;
}



void fun45()
{
    int arr[100];
    int arr_length = ReadPositiveNumber("enter array element size:\n");

    FillArrayWithRandomNumbers_minus100_100(arr, arr_length);

    cout << "\narray element:\n";
    PrintArray(arr, arr_length);

    cout << "\nnegative numbers count is: " << CountNegativeNumberInArray(arr, arr_length) << endl;
}



void fun46()
{
    float number = ReadNumber("please enter a number: ");
    cout << "my abs: " << MyAbs(number) << endl;
    cout << "c++ abs: " << abs(number) << endl;
}



void fun47()
{
    float number = ReadNumber("please enter a number: ");
    cout << "my round: " << MyRound(number) << endl;
    cout << "c++ round: " << round(number) << endl;
}



void fun48()
{
    float number = ReadNumber("please enter a number: ");
    cout << "my floor: " << MyFloor(number) << endl;
    cout << "c++ floor: " << floor(number) << endl;
}



void fun49()
{
    float number = ReadNumber("please enter a number: ");
    cout << "my ceil: " << MyCeil(number) << endl;
    cout << "c++ ceil: " << ceil(number) << endl;
}



void fun50()
{
    float number = ReadNumber("please enter a number: ");
    cout << "my sqrt: " << MySqrt(number) << endl;
    cout << "c++ sqrt: " << sqrt(number) << endl;
}


int main()
{
    srand((unsigned)time(NULL));
    fun50();

    return 0;
}
