namespace _153504_Khrishchanovich_Lab6
{
    class Employee
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public bool Work { get; set; }

        public Employee(string name = "", int age = 0, bool Work = false)
        {
            Name = name;
            Age = age;
            this.Work = Work;
        }
    }
}
