/* You need to check all the usernames in a database. Here are some simple rules that users have to follow when creating their username.

- Usernames can only use alpha-numeric characters.
- The only numbers in the username have to be at the end. There can be zero or more of them at the end. Username cannot start with the number.
- Username letters can be lowercase and uppercase.
- Usernames have to be at least two characters long. A two-character username can only use alphabet letters as characters.

 */

let username = "JackOfAllTrades";
let userCheck = /^[a-z]{2,}\d*$|^[a-z]\d{2,}$/gi;
let result = userCheck.test(username);
