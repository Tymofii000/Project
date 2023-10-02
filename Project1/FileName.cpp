using System;

// Клас Address
class Address
{
    // Поля
private :string index;
    private string country;
    private string city;
    private string street;
    private string house;
    private string apartment;

    // Властивості з методами доступу
    public string Index
    {
        get { return index; }
        set { index = value; }
    }

        public string Country
        {
            get { return country; }
            set { country = value; }
        }

            public string City
            {
                get { return city; }
                set { city = value; }
            }

                public string Street
                {
                    get { return street; }
                    set { street = value; }
                }

                    public string House
                    {
                        get { return house; }
                        set { house = value; }
                    }

                        public string Apartment
                        {
                            get { return apartment; }
                            set { apartment = value; }
                        }
}

// Клас Converter
class Converter
{
    // Поля
    private double usd;
    private double eur;
    private double pln;

    // Конструктор
    public Converter(double usd, double eur, double pln)
    {
        this.usd = usd;
        this.eur = eur;
        this.pln = pln;
    }

    // Метод для конвертації з гривні в валюту
    public double ConvertToCurrency(double amount, string currency)
    {
        switch (currency.ToLower())
        {
        case "usd":
            return amount / usd;
        case "eur":
            return amount / eur;
        case "pln":
            return amount / pln;
        default:
            throw new ArgumentException("Невірна валюта");
        }
    }

    // Метод для конвертації з валюти в гривню
    public double ConvertToUah(double amount, string currency)
    {
        switch (currency.ToLower())
        {
        case "usd":
            return amount * usd;
        case "eur":
            return amount * eur;
        case "pln":
            return amount * pln;
        default:
            throw new ArgumentException("Невірна валюта");
        }
    }
}

// Клас Employee
class Employee
{
    // Поля
    private string lastName;
    private string firstName;
    private string position;
    private double salary;
    private double tax;

    // Конструктор
    public Employee(string lastName, string firstName)
    {
        this.lastName = lastName;
        this.firstName = firstName;
        this.position = "Співробітник";
    }

    // Метод для розрахунку окладу та податкового збору
    public void CalculateSalary(double baseSalary, int experience)
    {
        // Визначення окладу в залежності від посади та стажу
        if (experience >= 5)
        {
            salary = baseSalary * 1.2; // Додаткова надбавка для стажу більше 5 років
        }
        else
        {
            salary = baseSalary;
        }

        // Розрахунок податкового збору (просто для прикладу)
        tax = salary * 0.15;
    }

    // Виведення інформації про співробітника
    public void DisplayInfo()
    {
        Console.WriteLine("Прізвище: " + lastName);
        Console.WriteLine("Ім'я: " + firstName);
        Console.WriteLine("Посада: " + position);
        Console.WriteLine("Оклад: " + salary);
        Console.WriteLine("Податковий збір: " + tax);
    }
}

// Головна програма
class Program
{
    static void Main(string[] args)
    {
        // Створення об'єкту класу Address
        Address address = new Address
        {
            Index = "12345",
            Country = "Україна",
            City = "Київ",
            Street = "Вулиця Київська",
            House = "1",
            Apartment = "10"
        };

        // Виведення інформації про адресу
        Console.WriteLine("Адреса:");
        Console.WriteLine("Індекс: " + address.Index);
        Console.WriteLine("Країна: " + address.Country);
        Console.WriteLine("Місто: " + address.City);
        Console.WriteLine("Вулиця: " + address.Street);
        Console.WriteLine("Будинок: " + address.House);
        Console.WriteLine("Квартира: " + address.Apartment);

        // Створення об'єкту класу Converter
        Converter converter = new Converter(27.5, 33.0, 7.0);

        // Приклад конвертації
        double amountInUah = 1000.0;
        double amountInUsd = converter.ConvertToCurrency(amountInUah, "usd");
        Console.WriteLine("1000 грн = " + amountInUsd + " USD");

        // Створення об'єкту класу Employee
        Employee employee = new Employee("Петров", "Іван");
        employee.CalculateSalary(5000.0, 7); // Приклад розрахунку окладу та податкового збору
        employee.DisplayInfo(); // Виведення інформації про співробітника

        Console.ReadLine();
    }
}
