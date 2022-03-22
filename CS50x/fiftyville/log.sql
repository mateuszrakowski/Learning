-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get information about theft crime scene
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021 AND month = 7 AND day = 28
   AND street = "Humphrey Street";


-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.


-- Familiarize with witnesses interviews to move on
SELECT name, transcript
  FROM interviews
 WHERE (year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%thief%");


-- Check bakery security logs and get names who drive in/out
SELECT name, bakery_security_logs.activity
  FROM people
       JOIN bakery_security_logs
         ON people.license_plate = bakery_security_logs.license_plate
      WHERE year = 2021 AND month = 7 AND day = 28
        AND hour = 10 AND minute >= 15 AND minute <= 25;

-- +---------+----------+
-- |  name   | activity |
-- +---------+----------+
-- | Vanessa | exit     |
-- | Bruce   | exit     |
-- | Barry   | exit     |
-- | Luca    | exit     |
-- | Sofia   | exit     |
-- | Iman    | exit     |
-- | Diana   | exit     |
-- | Kelsey  | exit     |
-- +---------+----------+

-- withdrawing money from ATM earlier this morning
-- when leaving phone call less than minute
-- earliest flight out of fiftyville tomorrow
-- other person to purchase flight ticket
-- someone whispering to the phone for half an hour


-- Get suspects name, phone number and passport number
SELECT name, phone_number, passport_number
  FROM people
       JOIN bakery_security_logs
         ON people.license_plate = bakery_security_logs.license_plate
      WHERE year = 2021 AND month = 7 AND day = 28
        AND hour = 10 AND minute >= 15 AND minute <= 25;

-- +---------+----------------+-----------------+
-- |  name   |  phone_number  | passport_number |
-- +---------+----------------+-----------------+
-- | Vanessa | (725) 555-4692 | 2963008352      |
-- | Bruce   | (367) 555-5533 | 5773159633      |
-- | Barry   | (301) 555-4174 | 7526138472      |
-- | Luca    | (389) 555-5198 | 8496433585      |
-- | Sofia   | (130) 555-0289 | 1695452385      |
-- | Iman    | (829) 555-5269 | 7049073643      |
-- | Diana   | (770) 555-1861 | 3592750733      |
-- | Kelsey  | (499) 555-9472 | 8294398571      |
-- +---------+----------------+-----------------+

-- Try to get information about phone calls done after theft
SELECT people.name, caller, receiver, duration
  FROM phone_calls
       JOIN people
         ON phone_number = caller
            JOIN bakery_security_logs
              ON people.license_plate = bakery_security_logs.license_plate
           WHERE bakery_security_logs.year = 2021
             AND bakery_security_logs.month = 7
             AND bakery_security_logs.day = 28
             AND bakery_security_logs.hour = 10
             AND bakery_security_logs.minute >= 15
             AND bakery_security_logs.minute <= 25
             AND duration < 60;

-- +--------+----------------+----------------+----------+
-- |  name  |     caller     |    receiver    | duration |
-- +--------+----------------+----------------+----------+
-- | Bruce  | (367) 555-5533 | (375) 555-8161 | 45       |
-- | Bruce  | (367) 555-5533 | (455) 555-5315 | 31       |
-- | Sofia  | (130) 555-0289 | (996) 555-8899 | 51       |
-- | Diana  | (770) 555-1861 | (725) 555-3243 | 49       |
-- | Kelsey | (499) 555-9472 | (717) 555-1342 | 50       |
-- | Kelsey | (499) 555-9472 | (892) 555-8872 | 36       |
-- +--------+----------------+----------------+----------+

-- Get names of the calls receivers
SELECT name, phone_calls.receiver, duration
  FROM people
       JOIN phone_calls
         ON phone_number = receiver
            WHERE duration < 60
              AND receiver IN
                  (SELECT receiver
                     FROM phone_calls
                          JOIN people
                            ON phone_number = caller
                     JOIN bakery_security_logs
                       ON people.license_plate = bakery_security_logs.license_plate
                 WHERE bakery_security_logs.year = 2021
                   AND bakery_security_logs.month = 7
                   AND bakery_security_logs.day = 28
                   AND bakery_security_logs.hour = 10
                   AND bakery_security_logs.minute >= 15
                   AND bakery_security_logs.minute <= 25
                   AND duration < 60);

-- +-----------+----------------+----------+
-- |   name    |    receiver    | duration |
-- +-----------+----------------+----------+
-- | Jack      | (996) 555-8899 | 51       |
-- | Larry     | (892) 555-8872 | 36       |
-- | Robin     | (375) 555-8161 | 45       |
-- | Melissa   | (717) 555-1342 | 50       |
-- | Philip    | (725) 555-3243 | 49       |
-- | Charlotte | (455) 555-5315 | 31       |
-- +-----------+----------------+----------+

-- Get account numbers of people who called from bakery
SELECT people.name, account_number
  FROM bank_accounts
       JOIN people
         ON person_id = id
      WHERE phone_number IN
            (SELECT caller
            FROM phone_calls
                 JOIN people
                 ON phone_number = caller
            JOIN bakery_security_logs
              ON people.license_plate = bakery_security_logs.license_plate
       WHERE bakery_security_logs.year = 2021
         AND bakery_security_logs.month = 7
         AND bakery_security_logs.day = 28
         AND bakery_security_logs.hour = 10
         AND bakery_security_logs.minute >= 15
         AND bakery_security_logs.minute <= 25
         AND duration < 60);

-- +-------+----------------+
-- | name  | account_number |
-- +-------+----------------+
-- | Bruce | 49610011       |
-- | Diana | 26013199       |
-- +-------+----------------+


-- Who withdrew money from ATM
SELECT account_number, amount
  FROM atm_transactions
 WHERE (year = 2021 AND day = 28 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
   AND (account_number = "49610011" OR account_number = "26013199");

-- +----------------+--------+
-- | account_number | amount |
-- +----------------+--------+
-- | 49610011       | 50     |
-- | 26013199       | 35     |
-- +----------------+--------+

-- Check if any of suspects was a passenger of flight
SELECT people.name, flight_id, seat
FROM passengers
JOIN people
  ON people.passport_number = passengers.passport_number
WHERE name = "Bruce" OR name = "Diana";

-- +-------+-----------+------+
-- | name  | flight_id | seat |
-- +-------+-----------+------+
-- | Diana | 18        | 4C   |
-- | Diana | 24        | 2C   |
-- | Diana | 54        | 6C   |
-- | Bruce | 36        | 4A   |
-- +-------+-----------+------+

-- Check IDs flights and airports from suspects
SELECT people.name, origin_airport_id, destination_airport_id
FROM flights
JOIN passengers
ON flight_id = flights.id
JOIN people
  ON people.passport_number = passengers.passport_number
WHERE (name = "Bruce" OR name = "Diana") AND (year = 2021 AND month = 7 AND day = 29);

-- +-------+-------------------+------------------------+
-- | name  | origin_airport_id | destination_airport_id |
-- +-------+-------------------+------------------------+
-- | Diana | 8                 | 6                      |
-- | Bruce | 8                 | 4                      |
-- +-------+-------------------+------------------------+


-- Check where they flew
SELECT airports.id, abbreviation, full_name, city
  FROM airports
  JOIN flights
    ON origin_airport_id = airports.id OR destination_airport_id = airports.id
 WHERE (origin_airport_id = 8 AND year = 2021 AND month = 7 AND day = 29)
    OR (destination_airport_id = 6 AND year = 2021 AND month = 7 AND day = 29)
    OR (destination_airport_id = 4 AND year = 2021 AND month = 7 AND day = 29);