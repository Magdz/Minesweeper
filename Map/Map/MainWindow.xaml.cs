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
using System.IO.Ports;

namespace Map
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort ArduinoSerial = new SerialPort();
        bool run = true;
        string COM;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void ArduinoRead()
        {
            ArduinoSerial.BaudRate = 9600;
            ArduinoSerial.PortName = COM;
            Console.Write(COM);
            ArduinoSerial.Open();

            while (run)
            {
                string trigger = ArduinoSerial.ReadLine();
            }
        }

        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            COM = COMBox.SelectedValue.ToString();
            ArduinoRead();
        }

    }
}
