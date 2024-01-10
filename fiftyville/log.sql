-- used to view all schematics of tables
.schema

-- used to view individual tables
--airports              crime_scene_reports   people
--atm_transactions      flights               phone_calls
--bakery_security_logs  interviews
--bank_accounts         passengers
.tables

-- used to view descriptions from specific crime date and place
--{3 witnesses, crime time was 10:15am, location Humphrey Street Bakery, littering at 16:36 or 6:36pm}
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- using location to narrow selection I q through all transcripts with a mention of the bakery
--{thief left with in 10 minutes of the theft, withdrew money from Leggett Street atm, call was under a minute for get away
-- , plan to take earliest flight out, other person bought tickets}
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- narrow further with time and date {returns 8 suspects and their license plates}
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25;

-- matching up with a wintess testimate of seeing the thief withdraw money from leggett st atm{ Bruce, Diana, and Iman match previous query}
SELECT people.name, atm_transactions.transaction_type FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';

--view all calls that were less than a minute{numbers are given but no names :( }
SELECT caller,receiver FROM Phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

--- creates a table to list the names of callers who called and where called
ALTER TABLE phone_calls ADD caller_name TEXT;
ALTER TABLE phone_calls ADD called_name TEXT;

--to make sure catagories are added
.schema phone_calls
--
UPDATE phone_calls SET caller_name = people.name FROM people WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls SET called_name = people.name FROM people WHERE phone_calls.receiver = people.phone_number;

-- same command as line 27 but matches names to all callers{
    --bruce and diana are present but iman is not so
    --they are eliminated off suspect list}
SELECT caller,caller_name, called_name,receiver FROM Phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- .schema flights to see all schematics from flight
.schema flights

-- given info is {id:36, hour:8, minutes 20;, orig:8, dest:4}
SELECT id, hour, minute, origin_airport_id, destination_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1;

-- creates an additional table to give city names from origin and destination

ALTER TABLE flights ADD originS_airport_id INTERGER;
ALTER TABLE flights ADD destinationS_airport_id INTERGER;

-- update flights new tables to retrieve name of origin and destination cities

UPDATE flights SET originS_airport_id = airports.city FROM airports WHERE flights.origin_airport_id = airports.id;

UPDATE flights SET destinationS_airport_id = airports.city FROM airports WHERE flights.destination_airport_id = airports.id;

-- gives names of cities from origin and destination from the current and following day along with flight id: 36
SELECT id, hour, minute, originS_airport_id, destinationS_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1;

-- get schematics of flights and passengers and people to find hashable values
.schema flights
.schema passengers
.schema people

--knowing the thief is on the first flight out of fiftyville (flight 36)and is between bruce and diana
-- the person found on flight is bruce so he is our thief
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);

--now to find who received a call from bruce and is our accomplace
SELECT caller,caller_name, called_name,receiver FROM Phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Robin was the receiver of a call from Bruce so he is our accomplace

