import requests
from pprint import pprint
import unittest

    
def request():
    url = "http://localhost:8000/api/notfound"
    response = requests.get(url)
    return response
    
    
class NotFoundTest(unittest.TestCase):
    def test_not_found_request(self):
        response = request()
        pprint(response)
        self.assertEqual(requests.codes['not_found'], response.status_code)

