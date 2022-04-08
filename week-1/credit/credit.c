#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool check_validity(long long card_number);
void print_brand(long long card_number);

int main(void)
{

    long long card_number = get_long_long("Number: ");

    if (check_validity(card_number))
    {
        print_brand(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_product_sum(int number)
{

    int sum = 0;
    int has_two_digits = number / 10;

    if (!has_two_digits)
    {
        return number;
    }

    for (; number != 0; number /= 10)
    {
        sum += number % 10;
    }

    return sum;
}
int get_number_length(long long card_number)
{
    int length = 0;

    while (card_number != 0)
    {
        length++;
        card_number /= 10;
    }

    return length;
}
bool check_length_validity(long long card_number)
{

    int length = get_number_length(card_number);

    if (length != 13 &&
        length != 15 &&
        length != 16)
    {
        return false;
    }

    return true;
}
bool check_digits_validity(long long card_number)
{

    long long temp = card_number;
    temp /= 10;

    int sum = 0;

    while (temp != 0)
    {
        sum += get_product_sum((temp % 10) * 2);
        temp /= 100;
    }

    temp = card_number;

    while (temp != 0)
    {
        sum += get_product_sum(temp % 10);

        temp /= 100;
    }

    if ((sum % 10) != 0)
    {
        return false;
    }

    return true;
}
bool check_validity(long long card_number)
{

    if (!check_length_validity(card_number))
    {
        return false;
    }

    if (!check_digits_validity(card_number))
    {
        return false;
    }

    return true;
}
bool is_mastercard(long long card_number)
{

    int length = get_number_length(card_number);

    if (length != 16)
    {
        return false;
    }

    for (int i = 0; i < length - 2; i++)
    {
        card_number /= 10;
    }

    if (card_number >= 51 &&
        card_number <= 55)
    {
        return true;
    }

    return false;
}
bool is_amex_card(long long card_number)
{

    int length = get_number_length(card_number);

    if (length != 15)
    {
        return false;
    }

    for (int i = 0; i < length - 2; i++)
    {
        card_number /= 10;
    }

    if (card_number == 34 ||
        card_number == 37)
    {
        return true;
    }

    return false;

}
bool is_visa_card(long long card_number)
{

    int length = get_number_length(card_number);

    if (length != 16 && length != 13)
    {
        return false;
    }

    for (int i = 0; i < length - 1; i++)
    {
        card_number /= 10;
    }

    if (card_number != 4)
    {
        return false;
    }

    return true;
}
void print_brand(long long card_number)
{

    if (is_mastercard(card_number))
    {
        printf("MASTERCARD\n");
    }
    else if (is_amex_card(card_number))
    {
        printf("AMEX\n");
    }
    else if (is_visa_card(card_number))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}