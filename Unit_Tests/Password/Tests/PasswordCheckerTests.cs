using Microsoft.VisualStudio.TestTools.UnitTesting;
using ClassLibraryPassword;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibraryPassword.Tests
{
    [TestClass()]
    public class PasswordCheckerTests
    {
        [TestMethod()]
        public void Check_8_symbols_ReturnsTrue()
        {
            string password = "G54w67b)";
            bool expected = true;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod()]
        public void Check_more20_symbols_ReturnsTrue()
        {
            string password = "Vbsay7t58w3rtbwehf978rtg4wtg5f";
            bool expected = false;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.IsFalse(actual);
        }

        [TestMethod()]
        public void Check_less8_symbols_ReturnsTrue()
        {
            string password = "Cvb34";
            bool expected = false;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.IsFalse(actual);
        }
        [TestMethod()]
        public void Check_availability_numbers_ReturnsTrue()
        {
            string password = "G54w67b)7Y";
            bool expected = true;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod()]
        public void Check_absence_numbers_ReturnsTrue()
        {
            string password = "huiUykutd";
            bool expected = false;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.IsFalse(actual);
        }

        [TestMethod()]
        public void Check_availability_special_characters_ReturnsTrue()
        {
            string password = "By&k6V54#$j";
            bool expected = true;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod()]
        public void Check_absence_special_characters_ReturnsTrue()
        {
            string password = "huiUykutd";
            bool expected = false;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.IsFalse(actual);
        }

        [TestMethod()]
        public void Check_availability_uppercase_characters_ReturnsTrue()
        {
            string password = "hd87y)Yefu8J";
            bool expected = true;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod()]
        public void Check_absence_lowercase_characters_ReturnsTrue()
        {
            string password = "FGUHFGUIAUH";
            bool expected = false;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.IsFalse(actual);
        }

        [TestMethod()]
        public void Check_absence_uppercase_characters_ReturnsTrue()
        {
            string password = "hfhahfoihasohfu";
            bool expected = false;

            bool actual = PasswordChecker.validatePassword(password);

            Assert.IsFalse(actual);
        }
    }
}
