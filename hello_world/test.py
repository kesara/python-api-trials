import unittest
import helloworld


class HelloWorldTest(unittest.TestCase):
    def test_no_args(self):
        self.assertEqual(helloworld.hello(), 'Hello World!')

    def test_empty_arg(self):
        self.assertEqual(helloworld.hello(''), 'Hello World!')

    def test_args(self):
        names = ['John', 'Jane', 'Jeff' 'J', '\n', '\t']
        for name in names:
            self.assertEqual(
                helloworld.hello(name), 'Hello {}!'.format(name))

    def test_largename248(self):
        name = 'a'*248
        self.assertEqual(helloworld.hello(name), 'Hello {}!'.format(name))

    def test_largename249(self):
        name = 'a'*249
        with self.assertRaises(helloworld.Error):
            helloworld.hello(name)

if __name__ == '__main__':
    unittest.main()
