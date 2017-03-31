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

namespace Renamer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private DirHandler my_DirHandler = null;
        public MainWindow()
        {
            my_DirHandler = new DirHandler();
            dirTextBlock = new TextBlock();
            InitializeComponent();            
        }

        private void inputPathBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            my_DirHandler.path = inputPathBox.Text;
        }

        private void readButton_Click(object sender, RoutedEventArgs e)
        {
            dirTextBlock.Text = my_DirHandler.path;
        }
    }
}
