using System;
using System.IO;
using System.Text;
using System.Security.Cryptography;

namespace Security
{
    class Class1
    {
        private static int xorCode = 10000.GetHashCode();
        private static byte[] xorByteCode = BitConverter.GetBytes(xorCode * 5000);

        public static int SecureInt(int data)
        {
            return data ^ xorCode;
        }

        public static float SecureFloat(float data)
        {
            byte[] byt = BitConverter.GetBytes(data);

            for (int i = 0; i < byt.Length; i++)
            {
                byt[i] ^= xorByteCode[i];
            }
            return BitConverter.ToSingle(byt, 0);
        }

        public static string SecureString(string data)
        {
            string newText = "";

            for (int i = 0; i < data.Length; i++)
            {
                int charValue = Convert.ToInt32(data[i]); //get the ASCII value of the character
                charValue ^= xorCode; //xor the value
                newText += Convert.ToChar(charValue);
                //newText += char.ConvertFromUtf32(charValue); //convert back to string

            }
            return newText;
        }

        public static DateTime SecureDateTime(DateTime data)
        {
            string dateTime = data.ToString();
            string newText = "";

            for (int i = 0; i < dateTime.Length; i++)
            {
                int charValue = Convert.ToInt32(dateTime[i]); //get the ASCII value of the character
                charValue ^= xorCode; //xor the value
                newText += Convert.ToChar(charValue);
                //newText += char.ConvertFromUtf32(charValue); //convert back to string

            }
            return Convert.ToDateTime(newText);
        }

        static void Main(string[] args)
        {
            DateTime d = DateTime.Now;

            Console.WriteLine("기본값 :" + d);
            Console.WriteLine("암호화 :" + SecureDateTime(d));
            Console.WriteLine("복호화 :" + SecureDateTime(SecureDateTime(d)));
        }
    }
}
