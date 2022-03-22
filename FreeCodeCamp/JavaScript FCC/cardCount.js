/* In the casino game Blackjack, a player can gain an advantage over the house by keeping track of the relative number of high and low cards remaining in the deck. This is called Card Counting.

Having more high cards remaining in the deck favors the player. Each card is assigned a value according to the table below. When the count is positive, the player should bet high. When the count is zero or negative, the player should bet low. */

/* Function checks if the player should bet or hold according to the cards drawn. */

let count = 0;

function cc(card) {
	switch (card) {
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			count = count + 1;
			break;

		case 7:
		case 8:
		case 9:
			count = count + 0;
			break;

		case 10:
		case "J":
		case "Q":
		case "K":
		case "A":
			count = count - 1;
			break;
	}

	if (count > 0) {
		return count + " Bet";
	} else if (count <= 0) {
		return count + " Hold";
	}
}

cc(2);
cc(5);
cc("J");
cc(7);
cc(3);
console.log(cc(4));
