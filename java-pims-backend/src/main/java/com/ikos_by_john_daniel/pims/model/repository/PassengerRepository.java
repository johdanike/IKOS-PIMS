package com.ikos_by_john_daniel.pims.model.repository;


import com.ikos_by_john_daniel.pims.model.data.Passenger;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Lock;
import jakarta.persistence.LockModeType;
import java.util.Optional;
import java.util.UUID;

public interface PassengerRepository extends JpaRepository<Passenger, UUID> {

    @Lock(LockModeType.PESSIMISTIC_WRITE)
    Optional<Passenger> findById(UUID id);
}