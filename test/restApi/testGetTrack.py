#!/usr/bin/env python 
import requests
from pprint import pprint
import unittest

    
def request():
    url = "http://localhost:8000/api/tracks"
    payload = {'track_id': '123', 'user': 'testUsr', 'password':'testPass'}
    response = requests.get(url, params=payload)
    return response
    
    
    
class GetTrackTest(unittest.TestCase):
    def test_get_track_request(self):
        response = request()
        pprint(response)
        self.assertEqual(requests.codes['ok'], response.status_code)
