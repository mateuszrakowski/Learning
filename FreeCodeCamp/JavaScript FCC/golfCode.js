/* In the game of golf, each hole has a par, meaning, the average number of strokes a golfer is expected to make in order to sink the ball in the hole to complete the play. 
Depending on how far above or below par your strokes are, there is a different nickname. */

/* Function below returns the correct string according to the score. */

const golfNicknames = [
	"Hole-in-one!",
	"Eagle",
	"Birdie",
	"Par",
	"Bogey",
	"Double Bogey",
	"Go Home!",
];

function golfScore(par, strokes) {
	if (strokes == 1) {
		return golfNicknames[0];
	} else if (strokes <= par - 2) {
		return golfNicknames[1];
	} else if (strokes == par - 1) {
		return golfNicknames[2];
	} else if (strokes == par) {
		return golfNicknames[3];
	} else if (strokes == par + 1) {
		return golfNicknames[4];
	} else if (strokes == par + 2) {
		return golfNicknames[5];
	} else if (strokes >= par + 3) {
		return golfNicknames[6];
	}
}

console.log(golfScore(4, 5));
