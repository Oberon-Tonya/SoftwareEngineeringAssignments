using Microsoft.VisualStudio.TestTools.UnitTesting;
using Assignment03_2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Assignment03_2.Tests
{
    [TestClass()]
    public class BusinessTests
    {
        [TestMethod()]
        public void TestInvalid()
        {
            Business b = new Business(float.NaN);
            try
            {
                float t = b.Tax;
            }
            catch(Exception e)
            {
                Assert.AreEqual(e.Message, "Invalid turnover");
            }
            b.Turnover = float.NegativeInfinity;
            try
            {
                float t = b.Tax;
            }
            catch (Exception e)
            {
                Assert.AreEqual(e.Message, "Invalid turnover");
            }
            b.Turnover = float.PositiveInfinity;
            try
            {
                float t = b.Tax;
            }
            catch (Exception e)
            {
                Assert.AreEqual(e.Message, "Invalid turnover");
            }
            b.Turnover = -5000.00f;
            try
            {
                float t = b.Tax;
            }
            catch (Exception e)
            {
                Assert.AreEqual(e.Message, "Invalid turnover");
            }
        }
        public void TestTax()
        {
            Business b = new Business();
            b.Turnover = 500.00f;
            Assert.AreEqual(b.Tax, 0.00f, float.Epsilon);
            b.Turnover = 1000.00f;
            Assert.AreEqual(b.Tax, 0.00f, float.Epsilon);
            b.Turnover = 2500.00f;
            Assert.AreEqual(b.Tax, 75.00f, float.Epsilon);
            b.Turnover = 5000.00f;
            Assert.AreEqual(b.Tax, 200.00f, float.Epsilon);
            b.Turnover = 7500.00f;
            Assert.AreEqual(b.Tax, 400.00f, float.Epsilon);
            b.Turnover = 10000.00f;
            Assert.AreEqual(b.Tax, 600.00f, float.Epsilon);
            b.Turnover = 20000.00f;
            Assert.AreEqual(b.Tax, 1600.00f, float.Epsilon);
        }
    }
}