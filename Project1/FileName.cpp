using System;

// ���� Address
class Address
{
    // ����
private :string index;
    private string country;
    private string city;
    private string street;
    private string house;
    private string apartment;

    // ���������� � �������� �������
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

// ���� Converter
class Converter
{
    // ����
    private double usd;
    private double eur;
    private double pln;

    // �����������
    public Converter(double usd, double eur, double pln)
    {
        this.usd = usd;
        this.eur = eur;
        this.pln = pln;
    }

    // ����� ��� ����������� � ����� � ������
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
            throw new ArgumentException("������ ������");
        }
    }

    // ����� ��� ����������� � ������ � ������
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
            throw new ArgumentException("������ ������");
        }
    }
}

// ���� Employee
class Employee
{
    // ����
    private string lastName;
    private string firstName;
    private string position;
    private double salary;
    private double tax;

    // �����������
    public Employee(string lastName, string firstName)
    {
        this.lastName = lastName;
        this.firstName = firstName;
        this.position = "����������";
    }

    // ����� ��� ���������� ������ �� ����������� �����
    public void CalculateSalary(double baseSalary, int experience)
    {
        // ���������� ������ � ��������� �� ������ �� �����
        if (experience >= 5)
        {
            salary = baseSalary * 1.2; // ��������� �������� ��� ����� ����� 5 ����
        }
        else
        {
            salary = baseSalary;
        }

        // ���������� ����������� ����� (������ ��� ��������)
        tax = salary * 0.15;
    }

    // ��������� ���������� ��� �����������
    public void DisplayInfo()
    {
        Console.WriteLine("�������: " + lastName);
        Console.WriteLine("��'�: " + firstName);
        Console.WriteLine("������: " + position);
        Console.WriteLine("�����: " + salary);
        Console.WriteLine("���������� ���: " + tax);
    }
}

// ������� ��������
class Program
{
    static void Main(string[] args)
    {
        // ��������� ��'���� ����� Address
        Address address = new Address
        {
            Index = "12345",
            Country = "������",
            City = "���",
            Street = "������ �������",
            House = "1",
            Apartment = "10"
        };

        // ��������� ���������� ��� ������
        Console.WriteLine("������:");
        Console.WriteLine("������: " + address.Index);
        Console.WriteLine("�����: " + address.Country);
        Console.WriteLine("̳���: " + address.City);
        Console.WriteLine("������: " + address.Street);
        Console.WriteLine("�������: " + address.House);
        Console.WriteLine("��������: " + address.Apartment);

        // ��������� ��'���� ����� Converter
        Converter converter = new Converter(27.5, 33.0, 7.0);

        // ������� �����������
        double amountInUah = 1000.0;
        double amountInUsd = converter.ConvertToCurrency(amountInUah, "usd");
        Console.WriteLine("1000 ��� = " + amountInUsd + " USD");

        // ��������� ��'���� ����� Employee
        Employee employee = new Employee("������", "����");
        employee.CalculateSalary(5000.0, 7); // ������� ���������� ������ �� ����������� �����
        employee.DisplayInfo(); // ��������� ���������� ��� �����������

        Console.ReadLine();
    }
}
