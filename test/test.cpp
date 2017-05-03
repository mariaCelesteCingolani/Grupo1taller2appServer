#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "Track.h"
#include "DBManager.h"


TEST(TrackTest, Create) {
	Track t("abs", "mp3", 0, NULL);
    EXPECT_EQ ("abs", t.id);
    EXPECT_EQ ("mp3", t.type);
    EXPECT_EQ (0, t.size);
    EXPECT_EQ (NULL, t.buffer);
}

TEST(TrackTest, SaveData) {
	Track t("abs", "mp3", 0, NULL);
	std::string mssg = "some mssg";
	const char * charmssg = mssg.c_str();
	t.copyAndSave (charmssg, mssg.length());
    EXPECT_EQ (mssg.length(), t.size);
}


TEST(DBManager, AddTrack) {
	char* buff = new char[10];
	Track track("abc", "mp3", 10, buff);
	DBManager d("mongodb://localhost:27017");
	bool result = d.addTrack(&track);
	// NEW TRACK
	EXPECT_TRUE(result);
	// A TRACK WITH THE SAME ID
	result = d.addTrack(&track);
	EXPECT_FALSE(result);
}

TEST(DBManager, GetTrack) {
	Track * track = NULL;
	DBManager d("mongodb://localhost:27017");
	track = d.getTrack("abc");
	EXPECT_TRUE(track != NULL);
	EXPECT_EQ (track->id, "abc");
}

TEST(DBManager, DeleteTrack) {
	DBManager d("mongodb://localhost:27017");
	bool result = d.deleteTrack("abc");
	EXPECT_TRUE(result);
	Track * track = d.getTrack("abc");
	EXPECT_TRUE (track == NULL);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
