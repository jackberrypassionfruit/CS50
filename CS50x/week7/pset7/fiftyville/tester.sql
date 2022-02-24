SELECT name, phone_number, passport_number FROM people

WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute >= 5 AND minute <= 25 AND activity = "exit")

AND id IN 
(SELECT person_id FROM bank_accounts, atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE month = 7 AND day = 28);