const contacts = [
	{
		firstName: "Akira",
		lastName: "Laine",
		number: "0543236543",
		likes: ["Pizza", "Coding", "Brownie Points"],
	},
	{
		firstName: "Harry",
		lastName: "Potter",
		number: "0994372684",
		likes: ["Hogwarts", "Magic", "Hagrid"],
	},
	{
		firstName: "Sherlock",
		lastName: "Holmes",
		number: "0487345643",
		likes: ["Intriguing Cases", "Violin"],
	},
	{
		firstName: "Kristian",
		lastName: "Vos",
		number: "unknown",
		likes: ["JavaScript", "Gaming", "Foxes"],
	},
];

/* The function should check if name is an actual contact's firstName and the given property (prop) is a property of that contact.
If both are true, then return the "value" of that property.
If name does not correspond to any contacts then return the string No such contact.
If prop does not correspond to any valid properties of a contact found to match name then return the string No such property. */
/* My first attempt to accomplish the challenge - I tried to split every condition to separate loop */

function lookUpProfile(name, prop) {
	/* Checks if given 'name' argument is an actual contact and the given argument 'prop' is present as a key. */
	for (let i = 0; i < contacts.length; i++) {
		if (name == contacts[i]["firstName"] && contacts[i].hasOwnProperty(prop)) {
			return contacts[i][prop];
		}
	}

	/* If given argument 'name' is not in array as value but argument 'prop' is present returns with appropriate string. */
	for (let i = 0; i < contacts.length; i++) {
		if (name !== contacts[i]["firstName"] && contacts[i].hasOwnProperty(prop)) {
			return "No such contact";
		}
	}

	/* If given argument 'prop' is not present in our array, function returns appropriate string. */
	for (let i = 0; i < contacts.length; i++) {
		if (contacts[i].hasOwnProperty(prop) === false) {
			return "No such property";
		}
	}
}

/* Then I tried to make it working inside one loop*/

function lookUpProfile2(name, prop) {
	/* The for loop runs, starting at the first object in the contacts list. */
	for (let i = 0; i < contacts.length; i++) {
		/* If the firstName parameter passed into the function matches the value of the "firstName" key in the first object, the if statement passes. */
		if (contacts[i].firstName === name) {
			/* Then, we use .hasOwnProperty() method (checks if there’s a given property and returns a boolean) with prop as an argument.*/
			if (contacts[i].hasOwnProperty(prop)) {
				/* If it’s true, the value of prop is returned.  */
				return contacts[i][prop];
				/* If the second if statement fails, No such property is returned. */
			} else {
				return "No such property";
			}
		}
	}
	/* If the firstName parameter isn’t matched by the final contacts object, the for loop exits and No such contact is returned. */
	return "No such contact";
}

/* 3rd working solution */

function lookUpProfile(name, prop) {
	for (let i = 0; i < contacts.length; i++) {
		if (contacts[i]["firstName"] === name && contacts[i].hasOwnProperty(prop)) {
			return contacts[i][prop];
		} else if (
			contacts[i]["firstName"] === name &&
			contacts[i].hasOwnProperty(prop) == false
		) {
			return "No such property";
		}
	}
	return "No such contact";
}
