using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Lotto
{
    public class LottoProgram
    {
        int[] lottoNumArray = new int[45];
        private void Lotto()
        {
            int i;
            for (i = 0; i < lottoNumArray.Length; ++i)
            {
                lottoNumArray[i] = i + 1;
            }

            List<int> chooseNumList = new List<int>();
            int tempNum = 0;

            System.Random random = new System.Random();

            i = 0;

            while (i < 6)
            {
                tempNum = random.Next(0, 45);
                if (!chooseNumList.Contains(lottoNumArray[tempNum]))
                {
                    chooseNumList.Add(lottoNumArray[tempNum]);
                    ++i;
                }
            }

            chooseNumList = chooseNumList.OrderBy(r => r).ToList();

            Console.WriteLine("LottoNum = " + chooseNumList[0]
                + ", " + chooseNumList[1] + ", " + chooseNumList[2]
                + ", " + chooseNumList[3] + ", " + chooseNumList[4]
                + ", " + chooseNumList[5]);
        }

        public static void Main(string[] args)
        {
            LottoProgram lp = new LottoProgram();
            lp.Lotto();
        }
    }
}
