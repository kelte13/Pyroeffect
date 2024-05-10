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

namespace Pyroeffect
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public SeriesCollection SeriesCollection { get; set; }

        private List<uint> data;

        public MainWindow()
        {
            InitializeComponent();

            // Инициализация данных примером случайных значений (замените этот код на ваш ввод данных)
            data = new List<uint>();
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
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += Timer_Tick;
            timer.Start();

            // Привязка данных к элементам управления графика
            DataContext = this;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            // Обновление данных графика
            RandomizeData();
            UpdateChart();
        }

        private void RandomizeData()
        {
            Random random = new Random();
            data.Clear();
            for (int i = 0; i < 10; i++)
            {
                data.Add((uint)random.Next(0, ushort.MaxValue));
            }
        }

        private void UpdateChart()
        {
            // Очистка старых значений
            SeriesCollection[0].Values.Clear();

            // Добавление новых значений
            foreach (uint value in data)
            {
                SeriesCollection[0].Values.Add(new ObservableValue(value));
            }
        }
    }
}
