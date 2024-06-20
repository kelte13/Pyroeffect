using LiveCharts.Defaults;
using LiveCharts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using LiveCharts.Wpf;
using System.IO;
using System.Xml.Linq;

namespace Pyroeffect
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public SeriesCollection SeriesCollection { get; set; }

        private List<string> data;
        private int currentIndex = 0;

        public MainWindow()
        {
            InitializeComponent();

            // Инициализация данных примером случайных значений (замените этот код на ваш ввод данных)
            data = new List<string>();
            RandomizeData();

            // Создание серии данных для графика
            SeriesCollection = new SeriesCollection
            {
                new LineSeries
                {
                    Title = "Data",
                    Values = new ChartValues<ObservableValue>()
                }
            };

            // Запуск таймера для обновления данных графика в реальном времени
            DispatcherTimer timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromMilliseconds(250);
            timer.Tick += Timer_Tick;
            timer.Start();

            // Привязка данных к элементам управления графика
            DataContext = this;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            // Добавление нового значения на график
            if (currentIndex < data.Count)
            {
                string value = data[currentIndex];
                string value1 = value.Replace('.', ',');
                if (double.TryParse(value1, out double numericValue))
                {
                    SeriesCollection[0].Values.Add(new ObservableValue(numericValue));
                    currentIndex++;
                }
                else
                {
                    // Handle the case where value is not a valid double
                    // For example, you can log a warning or skip adding this value to the chart
                }
            }
        }

        private void RandomizeData()
        {
            // Считывание данных из файла и добавление их в список
            using (StreamReader sr = new StreamReader("C:\\Users\\DMITRIY\\Documents\\GitHub\\Pyroeffect\\max6675\\file\\temperature.txt"))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    Console.WriteLine(line);
                    data.Add(line);
                }
            }
        }
    }
}