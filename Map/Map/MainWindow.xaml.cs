using System;
using System.Threading;
using System.Windows;
using System.IO.Ports;
using System.Windows.Controls;
using System.Windows.Shapes;
using System.Windows.Media;
using System.Windows.Threading;

namespace Map
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        static Grid Ground;
        static SolidColorBrush ColorBrush = new SolidColorBrush();

        static SerialPort ArduinoSerial = new SerialPort();
        static bool run = true;
        static string COM;
        Thread ArduinoThread = new Thread(new ThreadStart(ArduinoRead));

        static int mapLength = 9;
        static int column = 0;
        static int row = 9;
        static bool left = true;

        public MainWindow()
        {
            InitializeComponent();
            Ground = PlayGroundGrid;
            ColorBrush.Color = Color.FromArgb(255, 255, 0, 0);
            ArduinoThread.IsBackground = true;
        }

        private static void ArduinoRead()
        {
            ArduinoSerial.BaudRate = 9600;
            ArduinoSerial.PortName = COM;
            Console.WriteLine(COM);
            try
            {
                ArduinoSerial.Open();
            }
            catch (Exception)
            {
                return;
            }

            while (run)
            {
                int trigger = 0;
                try
                {
                    trigger = int.Parse(ArduinoSerial.ReadLine());
                }
                catch (Exception)
                {
                    Console.WriteLine("Wrong Input Format");
                }
                Console.WriteLine(trigger);
                if(trigger == 1)
                {
                    // Bomb Triggered
                    int target = row * (mapLength+1) + column;
                    Application.Current.Dispatcher.Invoke(
                        new Action(() => ((Rectangle)Ground.Children[target]).Fill = ColorBrush)
                    );
                }
                else if(trigger == 2)
                {
                    // Increment Location
                    if (left)
                    {
                        column++;
                    }
                    else
                    {
                        column--;
                    }
                    if(column < 0 || column > mapLength)
                    {
                        row--;
                        left = !left;
                        if (left)
                        {
                            column++;
                        }
                        else
                        {
                            column--;
                        }
                    }
                }
            }
        }

        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            COM = COMBox.SelectedValue.ToString().Split(':')[1].Split(' ')[1];
            run = true;
            try
            {
                ArduinoThread.Start();
            }
            catch (Exception)
            {
                try
                {
                    ArduinoThread.Resume();
                }
                catch (Exception) { }
            }
            
        }

        private void StopButton_Click(object sender, RoutedEventArgs e)
        {
            run = false;
            while (!ArduinoThread.IsAlive) ;
            ArduinoThread.Suspend();
        }
    }
}
