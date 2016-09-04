using System;
using System.Threading;
using System.Windows;
using System.IO.Ports;

namespace Map
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        static SerialPort ArduinoSerial = new SerialPort();
        static bool run = true;
        static string COM;
        Thread ArduinoThread = new Thread(new ThreadStart(ArduinoRead));

        public MainWindow()
        {
            InitializeComponent();
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
                string trigger = ArduinoSerial.ReadLine();
                Console.WriteLine(trigger);
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
                ArduinoThread.Resume();
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
