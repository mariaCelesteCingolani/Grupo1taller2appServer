.. Music.io Server App restful API documentation master file, created by
   sphinx-quickstart on Wed Apr  5 15:56:18 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Music.io RESTFUL API documentation
===========================================================

.. toctree::
   :maxdepth: 2

.. Based on https://developer.spotify.com/web-api

Get a Track
-----------------------------------------
.. http:get:: v1/tracks/(int:track_id)

	Get a single track identified by its unique ID.

   :param track_id: tracks's unique id
   :type track_id: int

Get Tracks
-----------------------------------------
.. http:get:: v1/tracks

	Get a set of the requested tracks.

   :param tracks_id: Required. A comma-separated list of the IDs for the tracks. Maximum: 50 IDs.

Get Audio Features
-----------------------------------------
.. http:get:: v1/audio-features/(int:track_id)

	Get audio feature information for a single track identified by its unique ID.

   :param track_id: tracks's unique id
   :type track_id: int


Get An Album
-----------------------------------------
.. http:get:: v1/albums/(int:album_id)

	Get catalog information for a single album.

   :param album_id: album's unique id
   :type album_id: int

Get Several Albums
-----------------------------------------
.. http:get:: v1/albums

	Get a set of the requested tracks.

   :param album_ids: Required. A comma-separated list of the IDs for the albums. Maximum: 50 IDs.

Get an Album’s Tracks
-----------------------------------------
.. http:get:: v1/albums/(int:album_id)/tracks

	Get Spotify catalog information about an album’s tracks. 

   :param album_id: album's unique id
   :type album_id: int

Get An Artist
-----------------------------------------
.. http:get:: v1/artists/(int:artist_id)

	Get catalog information for a single artist identified by their unique ID

   :param artist_id: album's unique id
   :type artist_id: int

Get an Artist's Albums
-----------------------------------------
.. http:get:: v1/artists/(int:artist_id)/albums

	Get Spotify catalog information about an artist’s albums. 

   :param artist_id: album's unique id
   :type artist_id: int

	








Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

