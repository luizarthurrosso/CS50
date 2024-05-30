-- Keep a log of any SQL queries you execute as you solve the mystery.

-- checking wich tables I have access;
.schema

-- checking wich crimes happened on the date; id = 295, 10:15am, Backery, 3 witness.
SELECT id, description FROM crime_scene_reports WHERE YEAR = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- checking the witnesses' transcript; 10 minutes interval, ATM before the theft at Leggett Street, phone call for less than a minute saying about getting the earliest flight out of the city - the accomplice bought the tickets.
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- checking what happened at the bakery at the moment; possible plates:
-- +----------+---------------+
-- | activity | license_plate |
-- +----------+---------------+
-- | exit     | 5P2BI95       |
-- | exit     | 94KL13X       |
-- | exit     | 6P58WS2       |
-- | exit     | 4328GD8       |
-- | exit     | G412CB7       |
-- | exit     | L93JTIZ       |
-- | exit     | 322W7JE       |
-- | exit     | 0NTHK55       |
-- +----------+---------------+
SELECT activity, license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;

-- checking what transactions happened before the theft; possible accounts and amounts:
-- +----------------+--------+
-- | account_number | amount |
-- +----------------+--------+
-- | 28500762       | 48     |
-- | 28296815       | 20     |
-- | 76054385       | 60     |
-- | 49610011       | 50     |
-- | 16153065       | 80     |
-- | 25506511       | 20     |
-- | 81061156       | 30     |
-- | 26013199       | 35     |
-- +----------------+--------+
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

-- checking phone calls at the day that last less than a minute;
-- +----------+----------------+----------------+
-- | duration |     caller     |    receiver    |
-- +----------+----------------+----------------+
-- | 51       | (130) 555-0289 | (996) 555-8899 |
-- | 36       | (499) 555-9472 | (892) 555-8872 |
-- | 45       | (367) 555-5533 | (375) 555-8161 |
-- | 50       | (499) 555-9472 | (717) 555-1342 |
-- | 43       | (286) 555-6063 | (676) 555-6554 |
-- | 49       | (770) 555-1861 | (725) 555-3243 |
-- | 38       | (031) 555-6622 | (910) 555-3251 |
-- | 55       | (826) 555-1652 | (066) 555-9701 |
-- | 54       | (338) 555-6650 | (704) 555-2131 |
-- +----------+----------------+----------------+
SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- checking who took flights out of fiftyville;
-- +-----------------+
-- | passport_number |
-- +-----------------+
-- | 7214083635      |
-- | 1695452385      |
-- | 5773159633      |
-- | 1540955065      |
-- | 8294398571      |
-- | 1988161715      |
-- | 9878712108      |
-- | 8496433585      |
-- +-----------------+
SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour ASC, minute ASC LIMIT 1);

-- intersecting data to get the thief's name; Bruce.
SELECT name, id, phone_number FROM people WHERE
license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25)
AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"))
AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour ASC, minute ASC LIMIT 1));

-- checking who's the accomplice;
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(367) 555-5533");