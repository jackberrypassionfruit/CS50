-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE description LIKE "%humphrey%" AND month = 7 AND day = 28;
-- Check reports that mention Humphrey St on the day of the crime


SELECT name, transcript FROM interviews WHERE transcript LIKE "%Bakery%" AND month = 7 AND day = 28;
-- Checking for interviews of people at the right place and right time


SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute >= 5 AND minute <= 25 AND activity = "exit";
-- Checking Bakery Security Logs for cars that left within 10 minutes after robbery


SELECT account_number, amount FROM atm_transactions WHERE atm_location LIKE "%legget%" AND month = 7 AND day = 28 AND transaction_type = 'withdraw';
-- Checking Acc num and amount for people who withdrew money on Legget St the day of the robbery


SELECT name, phone_number, passport_number FROM people
WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute >= 5 AND minute <= 25 AND activity = "exit")
AND id IN 
(SELECT person_id FROM bank_accounts, atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE month = 7 AND day = 28);
-- Cross referencing people who withdrew money before the robbery with people who left the bakery right after the crime


SELECT caller, receiver FROM phone_calls
WHERE caller IN
(
    SELECT phone_number FROM people
    WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute >= 5 AND minute <= 25 AND activity = "exit")
    AND id IN 
    (SELECT person_id FROM bank_accounts, atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE month = 7 AND day = 28)
)
AND duration <= 60
AND day = 28;
-- Cross referencing people who withdrew money and left after, with people who made a short phone call under 1 minute that same day


SELECT flights.id, day, hour, full_name, abbreviation, city FROM flights, airports
ON flights.destination_airport_id = airports.id
WHERE month = 7 AND day = 29
ORDER BY hour ASC
LIMIT 1;
-- Check flights the day AFTER the robbery


SELECT name FROM passengers, flights, people
ON passengers.flight_id = flights.id AND passengers.passport_number = people.passport_number
WHERE month = 7 AND day = 29
AND flights.id = 36
ORDER BY hour ASC;
-- People who flew to NYC the day after the robbery


SELECT name from people
WHERE phone_number = "(375) 555-8161";
-- Knowing that Bruce is the theif, check who the accomplic was that recieved his phone call after the robbery

