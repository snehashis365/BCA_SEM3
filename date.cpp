#include <iostream>

using namespace std;

class Date
{

private:
    int day, month, year;

    bool validateDate(int d, int m, int y)
    {
        if (y >= 1800 && y <= 9999)
        {
            if (m >= 1 && m <= 12)
            {
                if ((d >= 1 && d <= 31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                    return true;
                else if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                    return true;
                else if ((d >= 1 && d <= 28) && (m == 2))
                    return true;
                else if (d == 29 && m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
                    return true;
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1800;
        if (!validateDate(day, month, year))
        {
            cout << "Invalid Date";
        }
    }

    //Accessor functions
    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    //Mutator functions
    void setDate(int d, int m, int y)
    {
        if (validateDate(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            cout << "Invalid Date";
        }
    }

    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int countLeapYrs(int y, int m)
    {
        if (m <= 2)
            y--;
        return y / 4 - y / 100 + y / 400;
    }

    int findDifference(Date d)
    {

        long int n1 = year * 365 + day;
        for (int i = 0; i < month - 1; i++)
        {
            n1 += monthDays[i];
        }

        n1 += countLeapYrs(year, month);

        long int n2 = d.year * 365 + d.day;
        for (int i = 0; i < d.month - 1; i++)
        {
            n2 += monthDays[i];
        }

        n2 += countLeapYrs(d.year, d.month);

        return (n2 - n1);
    }

    //Add/Subtract days
    bool isLeap(int y)
    {
        if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
            return true;

        return false;
    }

    int offsetDays(int d, int m, int y)
    {
        int offset = d;
        switch (m - 1)
        {
        case 11:
            offset += 30;
        case 10:
            offset += 31;
        case 9:
            offset += 30;
        case 8:
            offset += 31;
        case 7:
            offset += 31;
        case 6:
            offset += 30;
        case 5:
            offset += 31;
        case 4:
            offset += 30;
        case 3:
            offset += 31;
        case 2:
            offset += 28;
        case 1:
            offset += 31;
        }

        if (isLeap(y) && m > 2)
            offset += 1;

        return offset;
    }

    void removeoffsetDays(int offset, int y, int *d, int *m)
    {
        int month[13] = {0, 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

        if (isLeap(y))
            month[2] = 29;

        int i;
        for (i = 1; i <= 12; i++)
        {
            if (offset <= month[i])
                break;
            offset = offset - month[i];
        }

        *d = offset + 1;
        *m = i;
    }

    void addDays(int x)
    {
        int offset1 = offsetDays(day, month, year);
        int remDays = isLeap(year) ? (366 - offset1) : (365 - offset1);

        int yRes, offset2;
        if (x <= remDays)
        {
            yRes = year;
            offset2 = offset1 + x;
        }
        else
        {
            x -= remDays;
            yRes = year + 1;
            int yResdays = isLeap(yRes) ? 366 : 365;
            while (x >= yResdays)
            {
                x -= yResdays;
                yRes++;
                yResdays = isLeap(yRes) ? 366 : 365;
            }
            offset2 = x;
        }

        int m2, d2;
        removeoffsetDays(offset2, yRes, &d2, &m2);
        year = yRes;
        day = d2;
        month = m2;
    }
    void subDays(int x)
    {
        int offset1 = offsetDays(day, month, year);

        int yRes, offset2;
        if (x <= offset1)
        {
            yRes = year;
            offset2 = offset1 - x - 2;
        }
        else
        {
            x -= offset1;
            yRes = year - 1;
            int yResdays = isLeap(yRes) ? 366 : 365;
            while (x >= yResdays)
            {
                x -= yResdays;
                yRes = year - 1;
                yResdays = isLeap(yRes) ? 366 : 365;
            }
            offset2 = yResdays - 2;
        }

        int m2, d2;
        removeoffsetDays(offset2, yRes, &d2, &m2);
        year = yRes;
        day = d2;
        month = m2;
    }

    bool checkEquality(Date d)
    {
        if (d.day == day && d.month == month && d.year == year)
            return true;
        else
            return false;
    }
};

int main()
{
    int d1, d2, m1, m2, y1, y2, ch;

    cout << "Enter the date in days, months and year: \n"
         << endl;
    cin >> d1 >> m1 >> y1;

    cout << "Enter the date in days, months and year for second date: \n"
         << endl;
    cin >> d2 >> m2 >> y2;

    Date date1, date2;
    date1.setDate(d1, m1, y1);
    date2.setDate(d2, m2, y2);

    cout << "Date 1:\n"
         << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << "\n\n"
         << endl;
    cout << "Date 2:\n"
         << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << "\n\n"
         << endl;

    cout << "Difference in dates: " << date1.findDifference(date2) << "\n"
         << endl;

    int days;
    cout << "1.for adding days\n2.for subtracting days\n3.for stopping here" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Enter number of days to add: \n"
             << endl;
        cin >> days;
        date1.addDays(days);

        cout << "New date: " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << "\n\n"
             << endl;
        break;
    case 2:
        cout << "Enter number of days to subtract: \n"
             << endl;
        cin >> days;
        date1.subDays(days);

        cout << "New date: " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << "\n\n"
             << endl;
        break;
    case 3:
        cout << "Thank You1" << endl;
        break;
    default:
        cout << "Invalid Option" << endl;
        break;
    }
    cout << "The days are " << ((date1.checkEquality(date2)) ? "equal\n" : "not equal\n") << endl;

    return 0;
}
