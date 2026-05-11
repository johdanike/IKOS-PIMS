package com.ikos_by_john_daniel.pims.controller;


import com.ikos_by_john_daniel.pims.model.data.Passenger;
import com.ikos_by_john_daniel.pims.model.repository.PassengerRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1/passengers")
public class PassengerController {

    @Autowired
    private PassengerRepository passengerRepository;

    @PostMapping
    public ResponseEntity<Passenger> registerPassenger(@RequestBody Passenger passenger) {
        Passenger savedPassenger = passengerRepository.save(passenger);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedPassenger);
    }
}