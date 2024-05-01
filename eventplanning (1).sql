-- Event Planning DATABASE

DROP DATABASE IF EXISTS eventplanning;

CREATE DATABASE eventplanning;

USE eventplanning;

-- Create tables

-- Venues
CREATE TABLE venues (
    venue_id INT PRIMARY KEY,
    venue_name VARCHAR(50),
    venue_location VARCHAR(50),
    capacity INT NOT NULL,
    contact_info VARCHAR(50)
);

-- Coordinators
CREATE TABLE coordinators (
    coordinator_id INT PRIMARY KEY,
    coordinator_name VARCHAR(50),
    service_offered VARCHAR(50),
    contact_info VARCHAR(50)
);

-- Vendors
CREATE TABLE vendors (
    vendor_id INT PRIMARY KEY,
    vendor_name VARCHAR(50),
    contact_info VARCHAR(50)
);

-- Decorators
CREATE TABLE decorators (
    decorator_id INT PRIMARY KEY,
    decorator_name VARCHAR(50),
    service_offered VARCHAR(50),
    contact_information VARCHAR(50)
);

-- Photographers
CREATE TABLE photographers (
    photographer_id INT PRIMARY KEY,
    photographer_name VARCHAR(50),
    service_offered VARCHAR(50),
    availab VARCHAR(50),
    contact_info VARCHAR(50)
);

-- Dressmaker
CREATE TABLE dressmaker (
    dress_id INT PRIMARY KEY,
    dressmaker_name VARCHAR(50),
    service_offered VARCHAR(50),
    availab VARCHAR(50),
    contact_info VARCHAR(50),
    dressmaker_address VARCHAR(50)
);

-- Bakeries
CREATE TABLE bakeries (
    store_id INT PRIMARY KEY,
    bakery_name VARCHAR(50),
    service_offered VARCHAR(50),
    contact_info VARCHAR(50)
);

-- Events
CREATE TABLE events (
    event_id INT PRIMARY KEY,
    event_name VARCHAR(50),
    event_date VARCHAR(50),
    event_type VARCHAR(50),
    venue_id INT,
    coordinator_id INT,
    FOREIGN KEY (venue_id) REFERENCES venues(venue_id),
    FOREIGN KEY (coordinator_id) REFERENCES coordinators(coordinator_id)
);

-- Contracts
CREATE TABLE contracts (
    contractNum INT PRIMARY KEY,
    event_id INT,
    vendor_id INT,
    contract_date VARCHAR(50),
    terms_conditions VARCHAR(50),
    payment_schedule VARCHAR(50),
    FOREIGN KEY (event_id) REFERENCES events(event_id),
    FOREIGN KEY (vendor_id) REFERENCES vendors(vendor_id)
);

-- Insert data into tables

-- Insert into venues
INSERT INTO venues (venue_id, venue_name, venue_location, capacity, contact_info)
VALUES
(111, 'Marthas venues', 'Outside', 250, '888-875-0099'),
(112, 'Jennys venues', 'Inside', 450, '888-887-9999'),
(113, 'Boutique venues', 'Inside and Outside', 130, '880-675-9908');

-- Insert into coordinators
INSERT INTO coordinators (coordinator_id, coordinator_name, service_offered, contact_info)
VALUES
(505, 'Jackie', 'Everything', '888-875-7786'),
(509, 'Martha', 'Everything', '223-885-0099'),
(513, 'Ricky', 'Everything', '878-854-0099');

-- Insert into vendors
INSERT INTO vendors (vendor_id, vendor_name, contact_info)
VALUES
(667, 'Kerra', '263-927-0098'),
(668, 'Jeffrey', '263-976-8298'),
(647, 'Kiara', '254-887-2238');

-- Insert into decorators
INSERT INTO decorators (decorator_id, decorator_name, service_offered, contact_information)
VALUES
(321, 'Maya', 'Weddings', '303-574-9393'),
(354, 'Simone', 'Parties', '262-734-9292'),
(357, 'Jay', 'Parties', '849-929-1672');

-- Insert into photographers
INSERT INTO photographers (photographer_id, photographer_name, service_offered, availab, contact_info)
VALUES
(1456, 'Jhonson', 'Weddings', 'May-August 2024', '565-729-8787'),
(2897, 'Wiggins', 'Parties', 'July-December 2024', '565-765-2301'),
(7895, 'Jeff', 'Weddings', 'April-May 2025', '563-787-0710');

-- Insert into dressmaker
INSERT INTO dressmaker (dress_id, dressmaker_name, service_offered, availab, contact_info, dressmaker_address)
VALUES
(6541, 'Dream dresses', 'Tailors', 'May 2024', '239-654-0909', '545 MLK BLVD Tallahassee, FL'),
(7852, 'Say Yes', 'Dress Designer', 'June 2024', '239-606-9075', '667 Capri Dr Tallahassee, FL'),
(1253, 'Dreamss', 'Tailors', 'May 2024', '239-654-0909', '608 MLK BLVD Tallahassee, FL');

-- Insert into bakeries
INSERT INTO bakeries (store_id, bakery_name, service_offered, contact_info)
VALUES
(421, 'Dream deserts', 'Cakes and Cookies', '234-589-0009'),
(452, 'Everything sweet', 'Everything', '234-445-0099'),
(489, 'Marthas Bakery', 'Everything', '234-769-9809');

-- Insert into events
INSERT INTO events (event_id, event_name, event_date, event_type, venue_id, coordinator_id)
VALUES
(101, 'Our Celebration', '2025-05-03', 'Wedding', 111, 505),
(102, '50th Birthday', '2024-11-03', 'Party', 112, 509),
(103, '21st Birthday', '2024-09-24', 'Party', 113, 513);

-- Insert into contracts
INSERT INTO contracts (contractNum, event_id, vendor_id, contract_date, terms_conditions, payment_schedule)
VALUES
(1023, 101, 667, 'May-June 2024', 'Signed', 'Biweekly'),
(1043, 102, 668, 'May-July 2024', 'Not-Signed', 'Biweekly'),
(1653, 103, 667, 'April-June 2024', 'Signed', 'Weekly');
