function rangeOfNumbers(startNum, endNum) {
	if (startNum == endNum) {
		return [startNum];
	} else {
		const array = rangeOfNumbers(startNum, endNum - 1);
		array.push(endNum);
		return array;
	}
}

console.log(rangeOfNumbers(5, 10));
